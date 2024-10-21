#pragma once

#include <list>
#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <SDL.h>
#include "sre/SpriteBatch.hpp"
#include "vector"
#include "Component.h"

namespace MyEngine {
	class Component;

	class GameObject {
		friend class Engine;

		// public API
	public:
		glm::vec2 position;
		float rotation;

		void Init();
		virtual void Update(float deltatime);
		virtual void Render(sre::SpriteBatch::SpriteBatchBuilder&);
		virtual void KeyEvent(SDL_Event&);

		void AddChild(std::shared_ptr<GameObject>);
		void AddComponent(std::shared_ptr<Component> component);

		std::string GetName();
		void SetName(std::string);
		void RemoveFromParent();
		bool MarkedForDeletion = false;

		// private fields
	private:
		std::weak_ptr<GameObject> _parent;
		std::weak_ptr<GameObject> _self;
		std::list<std::shared_ptr<GameObject>> _children = {};
		std::list< std::shared_ptr<Component>> _components = {};
		std::string _name;

	};
}