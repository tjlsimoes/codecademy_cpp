#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

#include "Task.hpp"
#include "TaskUtils.hpp"

int main() {
	const std::vector<std::string> names{
	"Spec Rev", "Parser", "Roadmap",
	"Fix CI", "UI Proto", "Metrics",
	"Sec Audit", "DB Mig", "Docs"
	};
	const std::vector<int> priorities{ 6, 9, 7, 8, 5, 6, 9, 8, 4 };
	const std::vector<double> times{ 1.0, 5.5, 2.5, 1.2, 3.0, 2.0, 4.0, 6.0, 1.5 };
	const std::vector<std::string> depts{
	"Product", "Engineering", "Product",
	"Engineering", "Design", "Data",
	"Security", "Engineering", "Product"
	};

	std::vector<int> idx(names.size());
	for (size_t i = 0; i < idx.size(); ++i) idx[i] = i;

	std::vector<Task> tasks(idx.size());

	std::cout << "== All ==" << std::endl;
	std::transform(idx.begin(), idx.end(), tasks.begin(),
			[&names, &priorities, &times, &depts](int i) {return Task(names[i], priorities[i], times[i], depts[i]);});

	for (const Task & task : tasks)
		task.print();

	std::cout << std::endl << "== Eng >2h ==" << std::endl;
	auto engLong = TaskUtils::filter(tasks, [](const Task & task) -> bool {
		if (task.getDepartment() == "Engineering" && task.getEstimatedTimeHours() > 2.0) 
			return true;
		else
			return false;});

	for (const Task & engTask : engLong)
		engTask.print();

	double shortThreshold = 1.5;
	int newlyDoneCount = 0;
	std::cout << std::endl << "== Short Tasks Done ==" << std::endl;
	TaskUtils::forEach(tasks, [&shortThreshold, &newlyDoneCount](Task & task) -> void {
		if (task.getEstimatedTimeHours() <= shortThreshold && task.isDone() != true)
		{
			task.setDone(true);
			std::cout << "Marked " << ++newlyDoneCount 
			<< " short tasks done" 
			<< std::endl;
		}
	});

	for (const Task & task : tasks)
		task.print();

	std::cout << std::endl << "== Priority ↓ ==" << std::endl;
	TaskUtils::sort(tasks, [](const Task &a, const Task &b) -> bool {
		if (a.getPriority() > b.getPriority())
			return true;
		else 
			return false;});

	for (const Task & task : tasks)
		task.print();

	std::cout << std::endl << "== Renamed [HOT] ==" << std::endl;
	std::vector<Task>	renamed = TaskUtils::apply(tasks, [](const Task & task) -> Task { 
		if (task.getPriority() >= 8) 
			return Task("[HOT] " + task.getName(), task.getPriority(), task.getEstimatedTimeHours(), task.getDepartment(), task.isDone());
		else
			return task;});

	for (const Task & renamedTask : renamed)
		renamedTask.print();


	std::cout << std::endl << "== Summary ==" << std::endl;
	auto summarize = [](const auto & list) {
		int		N = list.size();
		int		D = 0;
		double	H = 0;
		for (auto & elem : list)
		{
			if (elem.isDone() == true) D++;
			H += elem.getEstimatedTimeHours();
		}

		std::cout
		<< "Summary: " << N << " tasks, " << D 
		<< " done, total est. time = "<< H << "h"
		<< std::endl;
	};
	summarize(tasks);

	const std::string projectName = "Apollo";
	std::cout << std::endl << "== Project tag ==" << std::endl;
	auto showWithProject = [projectName](const Task & task) -> void {
		std::cout << task.getName() << std::endl;
		task.print();
	};
	for (const Task & task : tasks)
		showWithProject(task);

	int doneCount = 0;
	auto countDone = [&doneCount] (const Task & task) -> void {
		if (task.isDone())
			doneCount++;
	};
	for (const Task & task : tasks)
		countDone(task);
	
	std::cout
	<< "Done: " << doneCount
	<< std::endl;

	int	flaggedCount = 0;
	int	priorityThreshold = 7;
	auto countAbove = [priorityThreshold, &flaggedCount] (const Task & task) {
		if (task.getPriority() > priorityThreshold)
			flaggedCount++;
	};
	for (const Task & task : tasks)
		countAbove(task);
	std::cout
	<< "Flagged > 7: " << flaggedCount
	<< std::endl;


	int batchId = 42;
	std::cout << std::endl << "== First 3 (batch) ==" << std::endl;
	auto showWithBatch = [msg = "Batch-" + std::to_string(batchId)](const Task & task) -> void {
		std::cout << msg << " :: ";
		task.print();
		std::cout << std::endl;
	};
	for (size_t i = 0; (i < 3 && i < tasks.size()); i++)
		showWithBatch(tasks[i]);
	

	return 0;
}
