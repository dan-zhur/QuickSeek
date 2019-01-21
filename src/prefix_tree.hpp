#pragma once

#include <QChar>
#include <atomic>
#include <forward_list>
#include <list>
#include <thread>

class PrefixTree
{
public:
	//construction / deletion
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
	struct Node_ {
		bool isEndingNode_{ false }; //является ли последним для некоторого префикса
		std::forward_list< std::pair<std::string, Node_*> > nextNodes_;
	};
	//------------------------------

	//methods
	void DeleteMemory_(Node_* ptr);

	/*
	Проходит по строке, заданному итераторами и одновременно такой же путь
	делает в дереве. 
	В случае успеха, возвращает указатель на Node_, содержащий последний
	символ строки. В случае, если такой префикс не найден, возвращает nullptr.
	*/
	Node_* SkipToPrefixEnd(const std::string& prefix);

	/*
	Для для префикса, заканчивающемся в *ptr, вызывает callback(begin, end),
	где begin, end - итераторы для коллекции Char (которая представляет собой
	строку в дереве).
	*/
	template<typename Function>
	void SearchByPrefixHelper_(std::string prefix, Function callback);

	template<typename Function>
	void GoSearch_(Node_* ptr, Function callback, std::string& str);

	Node_* FindSymbolNodeAddress_(const std::string& symbol, const std::forward_list<std::pair<std::string, Node_*>>& nodes);
	//------------------------------


	//member variables
	Node_ *root_{ nullptr };
	std::atomic<bool> stopSearch_{ false }, isSearchRunning_{ false };
	std::thread searchThread_;
	//------------------------------
};


#include "prefix_tree.tpp"