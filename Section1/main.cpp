#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string name;
	char grade;
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map;

public:
	GradeMap()
	{

	}

	char& operator[](const std::string index);
};

char& GradeMap::operator[](const std::string index)
{
	for (auto &ref : m_map)
	{
		if (index == ref.name)
			return ref.grade;
	}

	m_map.push_back(StudentGrade{ index });
	return m_map.back().grade;

}

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}