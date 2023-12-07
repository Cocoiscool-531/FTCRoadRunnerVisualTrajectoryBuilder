#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

#include <Shader.h>
#include <Renderer.h>
#include <ImGui.h>

#include <NodeGrid.h>
#include <math.h>
#include <Save.h>

#include <filesystem>

GLFWwindow* window;
NodeGrid* grid;

GLFWwindow* getWindow(){
	return window;
}

int windowSize = 800;

int mouseX = 0;
int mouseY = 0;

bool shiftDown = false;

int main(int argc, char* argv[]){

	if(!std::filesystem::exists("save")){
		std::filesystem::create_directory("save");
	}

	if(!std::filesystem::exists("export")){
		std::filesystem::create_directory("export");
	}

	if(argc > 2){
		if(strcmp(argv[2], "4k") == 0){
			windowSize = 1700;
		}
	}

	bool running = true;
	glfwInit();

	window = glfwCreateWindow(windowSize * 2, windowSize, "FTC Roadrunner Visual Trajectory Builder", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, &running);
	glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);

	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	if(status == GL_FALSE){
		std::cout << "failed to init glad\n";
		return -1;
	}

	glfwSetWindowCloseCallback(window, [](GLFWwindow* window){
		bool* running = (bool*)glfwGetWindowUserPointer(window);
		*running = false;
	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int btn, int action, int mods){
		if(btn == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
			if(mouseX <= windowSize && mouseY <= windowSize){
				ImGuiIO io = ImGui::GetIO();
				if(!io.WantCaptureMouse){
					grid->mouseClick(mouseX, mouseY, windowSize, shiftDown);
				}
			}
		}
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y){
		mouseX = floor(x);
		mouseY = floor(y);
	});

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
		if(key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT){
			if(action == GLFW_PRESS){
				shiftDown = true;
			}
			if(action == GLFW_RELEASE){
				shiftDown = false;
			}
		}
	});

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Shader shader(R"(
		#version 330 core
		layout(location = 0) in vec2 pos;
		layout(location = 1) in vec2 itexUV;
		layout(location = 2) in vec4 itint;
		out vec2 texUV;
		out vec4 tint;
		void main(){
			texUV = itexUV;
			tint = itint;
			gl_Position = vec4(pos.x, pos.y, 0, 1);
		}
	)",
	R"(
		#version 330 core
		out vec4 color;
		in vec4 tint;
		in vec2 texUV;
		uniform sampler2D tex;
		void main(){
			if(tint.x == -1){
				color = texture(tex, texUV);
				color.x = color.x * -1 + 1;
				color.y = color.y * -1 + 1;
				color.z = color.z * -1 + 1;
				return;
			}
			color = texture(tex, texUV) * tint;
		}
	)");

	Renderer renderer;

	glm::vec4 verts[]{
		{0, 1, 0, 1},
		{0, -1, 0, 1},
		{-1, 1, 0, 1},
		{-1, -1, 0, 1}
	};

	Texture tex("field-2023-juice-dark.png");

	ImGuiClass imGui(windowSize);

	grid = new NodeGrid(&shader);

	if(argc > 1){
		if(strcmp(argv[1], "new")){
			Save::load(grid, argv[1]);
		}
	}

	if(argc > 2){
		if(strcmp(argv[2], "export") == 0){
			Save::exp(grid);
			running = false;
		}
	}

	while(running){
		glClearColor(0.1, 0.1, 0.1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();

		renderer.draw(verts, &tex, &shader, glm::vec4(1, 1, 1, 1));

		grid->update(renderer, mouseX, mouseY, windowSize, shiftDown);

		imGui.begin();
		imGui.nodeList(grid);
		imGui.nodeProperties(grid);
		imGui.end();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}