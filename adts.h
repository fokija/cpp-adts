#ifndef ADTS_H
#define ADTS_H

#include <vector>
#include <list>
#include <iostream>

class StackOfInts
{
    public:
        virtual int pop() = 0;
        virtual void push(int x) = 0;
        virtual bool isEmpty() = 0;
        virtual int size() = 0;
        virtual int peek() const = 0;
        virtual void printStack() = 0;
        virtual ~StackOfInts() {}
};

class QueueOfInts
{
    public:
        virtual void enqueue(int x) = 0;
        virtual int dequeue();
        virtual bool isEmpty() = 0;
        virtual int peek() const = 0;
        virtual void printQueue() = 0;
        virtual ~QueueOfInts() {}

};

class StackOfIntsImplVector : public StackOfInts
{
    public:

        StackOfIntsImplVector() : vectorOfInts() {} 
        int pop() override
        {
            if (vectorOfInts.empty() == true)
            {
                throw "Pop from empty stack exception";
            }
            int lastInt = vectorOfInts.back();
            vectorOfInts.pop_back();
            return lastInt;
        }
        void push(int x) override
        {
            vectorOfInts.push_back(x);
        }
        bool isEmpty() override
        {
            return vectorOfInts.empty();
        }
        int size() override
        {
            return vectorOfInts.size();
        }
        int peek() const override
        {
            if (vectorOfInts.empty() == true)
            {
                throw "Peek from empty stack exception";
            }
            return vectorOfInts.back();
        }
        void printStack() override
        {
            for (size_t i = 0; i < vectorOfInts.size(); i++)
            {
                std::cout << vectorOfInts[i] << "  ";
            }
            std::cout << std::endl;
        }
        ~StackOfIntsImplVector() override = default;
    private:
        std::vector<int> vectorOfInts;
};

class StackOfIntsImplList : public StackOfInts
{
    public:

        StackOfIntsImplList() : listOfInts() {} 
        int pop() override
        {
            int lastInt = listOfInts.back();
            listOfInts.pop_back();
            return lastInt;
        }
        void push(int x) override
        {
            listOfInts.push_back(x);
        }
        bool isEmpty() override
        {
            return listOfInts.empty();
        }
        int size() override
        {
            return listOfInts.size();
        }
        int peek() const override
        {
            return listOfInts.back();
        }
        void printStack() override
        {
            for (int i : listOfInts)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
        ~StackOfIntsImplList() override = default;
    private:
        std::list<int> listOfInts;
};

class QueueOfIntsImplVector : public QueueOfInts
{
    public:
        void enqueue(int x) override
        {
            vectorOfInts.push_back(x);
        }
        int dequeue() override
        {
            int firstInt = vectorOfInts.front();
            vectorOfInts.erase(vectorOfInts.begin());
            return firstInt;
        }
        bool isEmpty() override
        {
            return vectorOfInts.empty();
        }
        int peek() const override
        {
            return vectorOfInts.front();
        }
        void printQueue() override
        {
            for (size_t i = 0; i < vectorOfInts.size(); i++)
            {
                std::cout << vectorOfInts[i] << "  ";
            }
            std::cout << std::endl;
        }
        ~QueueOfIntsImplVector() override = default;
    private:
        std::vector<int> vectorOfInts;
};
class QueueOfIntsImlList : public QueueOfInts
{
    void enqueue(int x) override
    {
        listOfInts.push_back(x);
    }
    int dequeue() override
    {
        int firstInt = listOfInts.front();
        listOfInts.pop_front();
        return firstInt;
    }
    bool isEmpty() override
    {
        return listOfInts.empty();
    }
    int peek() const override
    {
        return listOfInts.front();
    }
    void printQueue() override
    {
        for (std::list<int>::iterator it = listOfInts.begin(); it != listOfInts.end(); ++it)
        {
            std::cout << *it << "  ";
        }
        std::cout << std::endl;
    }
    ~QueueOfIntsImlList() override = default;
    private:
        std::list<int> listOfInts;
};

#endif