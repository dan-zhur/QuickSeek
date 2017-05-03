#pragma once

#include "PrefixTree.h"



template<typename Container>
void PrefixTree::AddString(const Container& container)
{
	AddString(std::begin(container), std::end(container));
}



template<typename Iterator>
void PrefixTree::AddString(Iterator begin, Iterator end)
{
	if(root_ == nullptr)
	{
		root_ = new Node_;
	}
	Node_ *ptr = root_;
	for(; begin != end; ++begin)
	{
		Char c = *begin;
		Node_* cNode = FindSymbolNodeAddress_(c, ptr->nextNodes_);
		if(cNode == nullptr) //���� ���, �� ��������� �����, ����� ���
		{
			Node_ *temp = new Node_();
			ptr->nextNodes_.push_front(std::make_pair(c, temp));
			ptr = temp;
		}
		else //���� ������� � ������ ����, �� ������ ��������� �� ��������� �� ��������� �����
		{
			ptr = cNode;
		}
	}
	ptr->isEndingNode_ = true;
}



template<typename Function>
void PrefixTree::SearchByPrefix(const String& prefix, Function callback)
{
	stopSearch_ = false;
	isSearchRunning_ = true;
	searchThread_ = std::thread(&PrefixTree::SearchByPrefixHelper_<Function>, this, prefix, callback);
}



template<typename Function>
void PrefixTree::SearchByPrefixHelper_(String prefix, Function callback)
{
	Node_* ptr = SkipToPrefixEnd(prefix);
	if(ptr) //���� ���� ����� �������
	{
		GoSearch_(ptr, callback, prefix);
		callback(String{}); //����������, ��� ����� ��������
		isSearchRunning_ = false;
	}
}


//TODO: �������� ������������� ������

template<typename Function>
void PrefixTree::GoSearch_(Node_* ptr, Function callback, String& str)
{
	//TODO: ��������������
	if(stopSearch_.load())
	{
		return;
	}

	//���� � ������� ������� ������������� ����� ������
	if(ptr->isEndingNode_)
	{
		callback(str);
	}

	for(const std::pair<Char, Node_*>& it : ptr->nextNodes_)
	{
		str.push_back(it.first);
		GoSearch_(it.second, callback, str);
		str.pop_back();
	}
}
