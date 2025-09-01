#include "TaskUtils.hpp"

std::vector<Task> TaskUtils::filter(const std::vector<Task> & tasks, const std::function<bool(const Task &)> & predicate)
{
	bool keep;
	std::vector<Task> result;

	for (auto task : tasks)
	{
		keep = predicate(task);
		if (keep)
			result.push_back(task);
	}
	return result;
}

void					TaskUtils::forEach(std::vector<Task> & tasks, const std::function<void(Task &)> & op)
{
	for (Task & task : tasks)
		op(task);
}

void					TaskUtils::sort(std::vector<Task> & tasks, const std::function<bool(const Task &, const Task &)>& lessThan)
{
	size_t	bestIndex;
	size_t	j;
	size_t	i;
	for (i = 0; i < tasks.size(); i++)
	{
		bestIndex = i;
		for (j = i + 1; j < tasks.size(); j++)
		{
			if (lessThan(tasks[j], tasks[bestIndex]))
				bestIndex = j;
		};
		if (bestIndex != i)
			std::swap(tasks[i],tasks[bestIndex]);
	};
}

std::vector<Task>	TaskUtils::apply(const std::vector<Task> & tasks, const std::function<Task(const Task &)> & transformer)
{
	std::vector<Task>	result;
	for (Task task : tasks)
		result.push_back(transformer(task));
	return result;
}

