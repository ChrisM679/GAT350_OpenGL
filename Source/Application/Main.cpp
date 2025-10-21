
int main(int argc, char* argv[]) {
    neu::file::SetCurrentDirectory("Assets");
    LOG_INFO("current directory {}", neu::file::GetCurrentDirectory());

    // initialize engine
    LOG_INFO("initialize engine...");
    neu::GetEngine().Initialize();

    // initialize scene

    SDL_Event e;
    bool quit = false;

    //OPENGL Init
    std::vector<neu::vec3> points = {  {-0.5f, -0.5f, 0}, {0.0f,  0.5f, 0}, { 0.5f, -0.5f, 0} };
    std::vector<neu::vec3> colors = {   {1, 0, 0},         {0, 1, 0},        {0, 0, 1} };
    std::vector<neu::vec2> texcoords = { {0, 0},            {0.5f, 1},        {1, 1} };

    struct Vertex {
        neu::vec3 position;
        neu::vec3 color;
        neu::vec2 texcoord;
	};

    std::vector<Vertex> vertices{
        { {-0.5f, -0.5f, 0}, {1, 0, 0}, {0, 0} },
        { {-0.5f, 0.5f, 0}, {0, 1, 0}, {0, 1} },
        { {0.5f, 0.5f, 0}, {0, 0, 1}, {1, 1} },
        { {0.5f, -0.5f, 0}, {1, 0, 0}, {1, 0} }
    };

    std::vector<short> indices{ 0, 1, 2, 2, 3, 0 };

    //model
    auto model3d = std::make_shared<neu::Model>();
    model3d->Load("models/suzanne.obj");
    
    /*neu::res_t<neu::VertexBuffer> vb = std::make_shared<neu::VertexBuffer>();
    vb->CreateVertexBuffer((GLsizei)(sizeof(Vertex))* vertices.size(), (GLsizei)vertices.size(), vertices.data());
    vb->CreateIndexBuffer(GL_UNSIGNED_SHORT, indices.size(), indices.data());
    vb->SetAttribute(0, 3, sizeof(Vertex), offsetof(Vertex, position));
    vb->SetAttribute(1, 3, sizeof(Vertex), offsetof(Vertex, color));
    vb->SetAttribute(2, 2, sizeof(Vertex), offsetof(Vertex, texcoord));
    */

    //shader
    auto vs = neu::Resources().Get<neu::Shader>("shaders/basic.vert", GL_VERTEX_SHADER);
    auto fs = neu::Resources().Get<neu::Shader>("shaders/basic.frag", GL_FRAGMENT_SHADER);

	//program
    auto program = std::make_shared<neu::Program>();
    program->AttachShader(vs);
    program->AttachShader(fs);
    program->Link();
    program->Use();

	//texture
	neu::res_t<neu::Texture> texture = neu::Resources().Get<neu::Texture>("textures/beast.png");


    //uniform
	program->SetUniform("u_texture", 0);
    
    //transform
	float rotation = 0;
	glm::vec3 eye{ 0, 0, 5 };

    //projection matrix
    float aspect = (float)neu::GetEngine().GetRenderer().GetWidth() / (float)neu::GetEngine().GetRenderer().GetHeight();
    glm::mat4 projection = glm::perspective(glm::radians(60.0f), aspect, 0.01f, 100.0f);
    program->SetUniform("u_projection", projection);

    // MAIN LOOP
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // update
        neu::GetEngine().Update();
        float dt = neu::GetEngine().GetTime().GetDeltaTime();
        if (neu::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

		rotation += dt * 90;
        
		//model matrix
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
        program->SetUniform("u_model", model);
        
        //view matrix

		if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) eye.x += 1.0f * dt;
		if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) eye.x -= 1.0f * dt;
		if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) eye.z += 1.0f * dt;
		if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) eye.z -= 1.0f * dt;
		if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_Q)) eye.y += 1.0f * dt;
		if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_E)) eye.y -= 1.0f * dt;

        glm::mat4 view = glm::lookAt(eye, eye + glm::vec3{ 0, 0, -1 }, glm::vec3{ 0, 1, 0 });
        program->SetUniform("u_view", view);

        // draw
        neu::GetEngine().GetRenderer().Clear();

        model3d->Draw(GL_TRIANGLES);

        neu::GetEngine().GetRenderer().Present();
    }

    neu::GetEngine().Shutdown();

    return 0;
}
