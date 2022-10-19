#pragma once

#include <queue>
#include <utility>
#include <memory>

/******************************************
 * PIPE
 * This data structure is used to represent one-way
 * communication between two objects. 
 *****************************************/
class Pipe {
public:
	// constructors
	Pipe() = delete;
	Pipe(const Pipe& rhs) = delete;
	Pipe(const Pipe&& rhs) = delete;

	// v v v nested classes v v v

	/******************************************
	 * PIPE IN
	 * This represents the incoming end of the pipe.
	 * This should be used for the outgoing data in a
	 * one-way communication scenario.
	 *****************************************/
	template <class T>
	class In {
	public:
		// constructors
		In() : queue(nullptr) {}
		In(std::shared_ptr<std::queue<T>> queue) : queue(queue) {}

		// copy / move
		In(const In& rhs) : queue(rhs.queue) {}
		In(const In&& rhs) : queue(rhs.queue) {}
		In& operator=(const In& rhs)
		{
			queue = rhs.queue;
			return *this;
		}
		In& operator=(const In&& rhs)
		{
			queue = std::move(rhs.queue);
		}

		// load pipe
		void put(T element)
		{
			queue->push(element);
		}

		// polling
		size_t size()
		{
			return queue->size();
		}
	private:
		// underlying data structure
		std::shared_ptr<std::queue<T>> queue;
	};

	/******************************************
	 * PIPE OUT
	 * This represents the outgoing end of the pipe.
	 * This should be used for the incoming data in a
	 * one-way communication scenario.
	 *****************************************/
	template <class T>
	class Out {
	public:
		// constructors
		Out() : queue(nullptr) {}
		Out(std::shared_ptr<std::queue<T>> queue) : queue(queue) {}
		
		// copy / move
		Out(const Out& rhs) : queue(rhs.queue) {}
		Out(const Out&& rhs) : queue(rhs.queue) {}
		Out& operator=(const Out& rhs)
		{
			queue = rhs.queue;
			return *this;
		}
		Out& operator=(const Out&& rhs)
		{
			queue = rhs.queue;
			for (size_t i = 0; i < rhs.queue->size(); i++)
				rhs.queue->pop();
		}

		// unload pipe
		T get()
		{
			auto front = queue->front();
			queue->pop();
			return front;
		}

		// polling
		size_t size() 
		{
			return queue->size();
		}
	private:
		// underlying data structure
		std::shared_ptr<std::queue<T>> queue;
	};

	// ^ ^ ^ nested classes ^ ^ ^

	/******************************************
	 * GET PIPE
	 * This method returns a pair containing each side
	 * of a pipe. Each nested pipe object contains a 
	 * reference to the same underlying data structure.
	 *****************************************/
	template <class T>
	static std::pair<In<T>, Out<T>> getPipe()
	{
		auto queue = std::make_shared<std::queue<T>>();
		return { In<T>(queue), Out<T>(queue) };
	}
};