#include "MyEngine.h"

#include <random>

#include "sre/RenderPass.hpp"
#include "gameObject.h"

namespace MyEngine {
	Engine* Engine::_instance = nullptr;

	Engine::Engine() {
		assert(_instance == nullptr && " Only one instance of MyEngine::Engine allowed!");
		_instance = this;

		_root = std::make_shared<GameObject>();
		_root->SetName("root");
	}

	glm::vec2 Engine::GetScreenSize() const
	{
		return WIN_SIZE;
	}

	void Engine::Init() {
		// initializes random generator
		std::srand(std::time(nullptr));

		_camera.setWindowCoordinates();

		_root->Init();
	}

	void Engine::ProcessEvents(SDL_Event& event) {
		_root->KeyEvent(event);
	}

	void Engine::Update(float deltaTime) {
		++frame;
		time += deltaTime;
		_root->Update(deltaTime);
		Cleanup();
	}

	void Engine::Render()
	{
		sre::RenderPass renderPass = sre::RenderPass::create()
			.withCamera(_camera)
			.withClearColor(true, { .3f, .3f, 1, 1 })
			.build();

		sre::SpriteBatch::SpriteBatchBuilder spriteBatchBuilder = sre::SpriteBatch::create();

		_root->Render(spriteBatchBuilder);

		auto spriteBatch = spriteBatchBuilder.build();
		renderPass.draw(spriteBatch);
	}

	GameObject* Engine::CreateGameObject(std::string name) {
		auto ret = std::make_shared<GameObject>();
		ret->_self = ret;
		ret->_parent = _root;
		ret->SetName(name);
		_root->AddChild(ret);

		return ret.get();
	}

	void Engine::Cleanup() {
		std::vector<std::shared_ptr<GameObject>> toDelete;

		// Recursive lambda to traverse the scene graph
		std::function<void(std::shared_ptr<GameObject>)> traverse = [&](std::shared_ptr<GameObject> obj) {
			// Check if the current object is marked for deletion
			if (obj->MarkedForDeletion) {
				toDelete.push_back(obj);
			}
			// Traverse children
			for (const auto& child : obj->_children) {
				traverse(child);
			}
			};

		// Start traversal from the root
		traverse(_root);

		// Remove and cleanup marked objects
		for (const auto& obj : toDelete) {
			obj->RemoveFromParent(); // Assuming this method exists
		}

		// Optionally clear the toDelete vector
		toDelete.clear();
	}
}
