#pragma once

#include <QChar>
#include <atomic>
#include <forward_list>
#include <list>
#include <thread>


class PrefixTree {
public:
	//special members
	PrefixTree() = default;
	~PrefixTree();
	//------------------------------

	//methods
	template<typename Container>
	void AddString(const Container& container);

	template<typename Iterator>
	void AddString(Iterator begin, Iterator end);

	template<typename Function>
	void SearchByPrefix(const std::string& prefix, Function callback);

	void StopSearch();

	void WaitSearch();
	//------------------------------
private:
	//types
	struct _Node {
		bool _is_last_node{ false }; //является ли последним для некоторого префикса
		std::forward_list< std::pair<std::string, _Node*> > _child_nodes;
	};
	//------------------------------

	//methods
	void DeleteMemory_(_Node* ptr);

	/*
	Проходит по строке, заданному итераторами и одновременно такой же путь
	делает в дереве. 
	В случае успеха, возвращает указатель на _Node, содержащий последний
	символ строки. В случае, если такой префикс не найден, возвращает nullptr.
	*/
	_Node* SkipToPrefixEnd(const std::string& prefix);

	/*
	Для для префикса, заканчивающемся в *ptr, вызывает callback(begin, end),
	где begin, end - итераторы для коллекции Char (которая представляет собой
	строку в дереве).
	*/
	template<typename Function>
	void SearchByPrefixHelper_(std::string prefix, Function callback);

	template<typename Function>
	void GoSearch_(_Node* ptr, Function callback, std::string& str);

	_Node* FindSymbolNodeAddress_(const std::string& symbol, const std::forward_list<std::pair<std::string, _Node*>>& nodes);
	//------------------------------


	//member variables
	_Node *_root{ nullptr };
	std::atomic<bool> _stop_search{ false }, _is_search_running{ false };
	std::thread _search_thread;
	//------------------------------
};


#include "prefix_tree.tpp"
