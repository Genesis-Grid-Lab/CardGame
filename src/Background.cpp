#include "Graphics/Background.h"
#include "Application/Application.h"

BackGround::BackGround(Shader &shader, Texture2D &texture, Application* app)
    :m_Texture(texture), Position(glm::vec2(0.0f, 0.0f)), Size(glm::vec2(1280.0f, 720.0f)), Rotate(0.0f), Color(glm::vec3(1.0f))
{
    this->m_Shader = shader;
    this->initRenderData();
    //app->GetContext()->Renderer->LoadBackGround(this);
}

BackGround::~BackGround()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}


void BackGround::Draw()
{
    // prepare transformations
    this->m_Shader.Use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(Position, 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * Size.x, 0.5f * Size.y, 0.0f));
    model = glm::rotate(model, glm::radians(Rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * Size.x, -0.5f * Size.y, 0.0f));

    model = glm::scale(model, glm::vec3(Size, 1.0f));

    this->m_Shader.SetMatrix4("model", model);
    this->m_Shader.SetVector3f("spriteColor", Color);

    glActiveTexture(GL_TEXTURE0);
    m_Texture.Bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void BackGround::initRenderData()
{
    // configure VAO/VBO
    unsigned int VBO;

    float vertices[] = {
    //pos       //tex
    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,

    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
