/*#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct Job
{
	std::string id;
	int deadline;
	int profit;
	Job(std::string id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {};
};

bool compareJobProfits(const Job a, const Job b)
{
	return a.profit > b.profit;
}

int minPos(int num1, int num2)
{
	if (num1 > num2)
	{
		return num2;
	}
	
	return num1;
}

std::vector<Job> maxProfitSequence(std::vector<Job> jobs)
{
	std::sort(jobs.begin(), jobs.end(), compareJobProfits);
	
	std::vector<bool> timeSlots(jobs.size());
	std::vector<int> slotVal(jobs.size());
	bool empty = true;
	for (int i = 0; i < jobs.size(); ++i)
	{
		if (jobs[i].deadline > timeSlots.size() - 1)
		{
			timeSlots.resize(jobs[i].deadline + 1);
			std::cout << timeSlots.size() << std::endl;
		}

		int nrAvailableDays = timeSlots.size();

		for (int i = 0; i < jobs.size(); i++)
		{
			timeSlots[i] = false;
		}

		for (int i = 0; i < jobs.size(); i++)
		{
			std::cout << "min="<< minPos(jobs.size(), jobs[i].deadline) - 1 << std::endl;
			for (int j = minPos(jobs.size(), jobs[i].deadline) - 1; j >= 0; j--)
			{
				if (timeSlots[j] == false)
				{
					slotVal[j] = i;
					timeSlots[j] = true;
					break;
				}
			}
		}
	}

	std::vector<Job> maxProfitJobs;

	for (int i = 0; i < jobs.size(); ++i)
	{
		std::cout << std::endl;
		if (timeSlots[i])
		{
			maxProfitJobs.push_back(jobs[slotVal[i]]);
		}
	}

	return maxProfitJobs;
}

void JobSequencingProblem()
{
	std::vector<Job> jobs;
	jobs.emplace_back("a", 2, 100);
	jobs.emplace_back("b", 1, 19);
	jobs.emplace_back("c", 2, 27);
	jobs.emplace_back("d", 1, 25);
	jobs.emplace_back("e", 3, 15);
	std::vector<Job> sequence = maxProfitSequence(jobs);
	for (Job& j : sequence)
	{
		std::cout << j.id << " ";
	}
}

int main()
{
	JobSequencingProblem();
	return 0;
}*/