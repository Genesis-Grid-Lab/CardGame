#pragma once
#include "AppContext.h"

class AppInterface
{
public:
    inline virtual ~AppInterface() = default;

    //Attach evnt callback
    template <typename Event, typename Callback>
    inline void AttachCallback(Callback&& callback)
    {
        m_Context->Dispatcher.AttachCallback<Event>(std::move(callback), m_LayerID);
    }

    // post event
    template <typename Event, typename... Args>
    inline void PostEvent(Args&&...args)
    {
	m_Context->Dispatcher.PostEvent<Event>(std::forward<Args>(args)...);
    }

    // post task
    template <typename Task>
    inline void PostTask(Task&& task)
    {
	m_Context->Dispatcher.PostTask(std::move(task));
    }

    // detach callback
    template <typename Event>
    inline void DetachCallback()
    {
	m_Context->Dispatcher.DetachCallback<Event>(m_LayerID);
    }

    // Attach layer
    template <typename Layer, typename... Args>
    inline Layer* AttachLayer(Args&&... args)
    {
	// check layer's type compliance
	APP_STATIC_ASSERT(std::is_base_of<AppInterface, Layer>::value);

	// check if layer allready exist
	if(GetLayer<Layer>() != nullptr)
	{
	    ERROR("Layer allready attached");
	    return nullptr;
	}

	// create layer and add to collection
	auto layer = new Layer(std::forward<Args>(args)...);
	m_Context->Layers.push_back(layer);
	layer->m_LayerID = TypeID<Layer>();
	layer->m_Context = m_Context;
	layer->OnStart();
	return layer;
    }

    // detach layer
    template <typename Layer>
    inline void DetachLayer()
    {
	APP_STATIC_ASSERT(std::is_base_of<AppInterface, Layer>::value);
	m_Context->Dispatcher.PostTask([this]
	    {
		m_Context->Layers.erase(std::remove_if(m_Context->Layers.begin(),
						       m_Context->Layers.end(),
						       [this] (auto& layer)
						       {
							   if(layer->m_LayerID == TypeID<Layer>())
							   {
							       m_Context->Dispatcher.EraseListener(layer->m_LayerID);
							       DELETE(layer);
							       return true;
							   }
							   return false;
						       }),
					m_Context->Layers.end());
	    });
    }

    // retreive layer
    template <typename Layer>
    inline Layer* GetLayer()
    {
	APP_STATIC_ASSERT(std::is_base_of<AppInterface, Layer>::value);

	auto itr = std::find_if(m_Context->Layers.begin(),
				m_Context->Layers.end(),
				[this] (auto layer)
				{
				    return (layer->m_LayerID == TypeID<Layer>());
				});
	if(itr != m_Context->Layers.end())
	{
	    return static_cast<Layer*>(*itr);
	}

	return nullptr;
    }

    inline GLFWwindow* GetWindowHandle()
    {
	return m_Context->Window->Handle();
    }

  inline AppContext* GetContext()
  {
    return m_Context;
  }

protected:
    inline virtual void OnUpdate() {}
    inline virtual void OnStart() {}

private:
    friend class Application;
    AppContext* m_Context;
    uint32_t m_LayerID;
};
