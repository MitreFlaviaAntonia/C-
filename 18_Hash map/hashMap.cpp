#include <iostream>
#include <list>
#include <optional>

class hashMap
{
    private:
        int m_Capacity = 13337;
        std::list<std::pair<int, int>> mBuckets[13337];
        int hash(int key);

    public:
		bool insert(int key, int val);
		int& operator[](int key);
        bool contains(int key);
        std::optional<int> find(int key);
        void erase(int key); 
};

int hashMap::hash(int key)
{
	return key % m_Capacity;
}

bool hashMap::insert(int key, int value)
{
	int hashingIndex = hash(key);
	for (auto& pair : mBuckets[hashingIndex])
	{
		if (pair.first == key)
			return false;
	}
	mBuckets[hashingIndex].push_back(std::pair(key, value));
	return true;
}

int& hashMap::operator[](int key)
{
	int hashingIndex = hash(key);
	insert(key, 0);
	for (auto& pair : mBuckets[hashingIndex])
	{
		if (pair.first == key)
		{
			return pair.second;
		}
	}
	return key;
}

bool hashMap::contains(int key)
{
    int hashingIndex = hash(key);
	for (auto& pair : mBuckets[hashingIndex])
	{
		if (pair.first == key)
			return true;
	}
    return false;
}

std::optional<int> hashMap::find(int key)
{
    int hashingIndex = hash(key);
	for (auto& pair : mBuckets[hashingIndex])
	{
		if (pair.first == key)
			return pair.second;
	}
    return std::nullopt;
}

void hashMap::erase(int key)
{
    int hashingIndex = hash(key);
    for (auto it = mBuckets[hashingIndex].begin(); it != mBuckets[hashingIndex].end(); it++) //std::list<std::pair<int, int>>::iterator
    {
        if (it->first == key)
        {
            mBuckets[hashingIndex].erase(it);
            break;
        }
    }
}

int main()
{
	hashMap map;
	map.insert(1, 21);
	map.insert(2, 13);

	map[2] = 15;
	std::cout << "Value at key 2 after operator[]: " << map.find(2).value_or(-1) << std::endl;
	map[3] = 44;
	std::cout << "Value at key 3 after operator[]: " << map.find(3).value_or(-1) << std::endl;

	std::cout << "Does the map contain the key 1?" << std::endl;
	if (map.contains(1))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	std::cout << "Does the map contain the key 5?" << std::endl;
	if (map.contains(5))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	std::cout << "Value at key 1: " << map.find(1).value_or(-1) << std::endl;

	std::cout << "Does the key 3 exist? " << map.contains(3) << std::endl;
	map.erase(3);
	std::cout << "erase" << std::endl;

	std::cout << "Does the map contain the key 3? " << std::endl;
	if (map.contains(3))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
}