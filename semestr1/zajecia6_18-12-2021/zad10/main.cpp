#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student
{
    string name;
    vector<int> grades;
    float average;
};

struct group
{
    string nazwa;
    vector<student> studenci;
    float mediana_srednich;
};

void add_student_to_group(group &gr, student st)
{
    gr.studenci.push_back(st);
}

string best_groups_name(vector<group> gr_vec)
{
    group best = gr_vec.at(0);

    /* grupy w wektorze:
        gr.at(0) - grp1
        gr.at(1) - grp2
        gr.at(2) - grp3 */

    for (int i = 0; i < gr_vec.size(); i++)
    {
        if (gr_vec.at(i).mediana_srednich > best.mediana_srednich)
        {
            best = gr_vec.at(i);
        }
    }

    return best.nazwa;
}

float student_grades_average(student st)
{
    float sum = 0, average = 0;

    for (int i = 0; i < st.grades.size(); i++)
    {
        sum = sum + st.grades.at(i);
    }

    average = sum / st.grades.size();

    return average;
}

float group_averages_median(group gr)
{
    float median = 0;

    // Utworzenie wektora ze srednimi studentow do posortowania

    vector<float> students_averages = {};
    for (int i = 0; i < gr.studenci.size(); i++)
    {
        students_averages.push_back(gr.studenci.at(i).average);
    }

    cout << "srednie studentow w " << gr.nazwa << ": " << endl;
    for (int i = 0; i < students_averages.size(); i++)
    {
        cout << students_averages.at(i) << " ";
    }
    cout << endl;

    // Sortowanie srednich

    for (int i = 0; i < students_averages.size(); i++)
    {
        for (int j = 1; j < students_averages.size(); j++)
        {
            if (students_averages.at(j-1) > students_averages.at(j))
            {
                float tmp = 0;
                tmp = students_averages.at(j-1);
                students_averages.at(j-1) = students_averages.at(j);
                students_averages.at(j) = tmp;
            }
        }
    }

    cout << "posortowane srednie studentow w " << gr.nazwa << ": " << endl;
    for (int i = 0; i < students_averages.size(); i++)
    {
        cout << students_averages.at(i) << " ";
    }
    cout << endl;

    // Obliczanie mediany

    median = (students_averages.at((students_averages.size() - 1) / 2) + (students_averages.at(students_averages.size() / 2))) / 2;

    cout << "mediana " << gr.nazwa << ": " << median << endl <<  endl;

    return median;
}

int main()
{
    // Studenci

    struct student stud1;
        stud1.name = "Artur Szczesny";
        stud1.grades = {2,4,3,5};
        stud1.average = student_grades_average(stud1);

    struct student stud2;
        stud2.name = "Adam Kowalski";
        stud2.grades = {3,4,4,2};
        stud2.average = student_grades_average(stud2);

    struct student stud3;
        stud3.name = "Jan Nowak";
        stud3.grades = {2,4,3,3};
        stud3.average = student_grades_average(stud3);

    struct student stud4;
        stud4.name = "Zbigniew Malysz";
        stud4.grades = {4,5,2,2};
        stud4.average = student_grades_average(stud4);

    struct student stud5;
        stud5.name = "Wojciech Blaszczykowski";
        stud5.grades = {5,5,5,2};
        stud5.average = student_grades_average(stud5);

    struct student stud6;
        stud6.name = "Zbigniew Sienkiewicz";
        stud6.grades = {4,4,2,5};
        stud6.average = student_grades_average(stud6);

    struct student stud7;
        stud7.name = "Patryk Mickiewicz";
        stud7.grades = {4,2,2,5};
        stud7.average = student_grades_average(stud7);

    // Grupy

    struct group grp1;
        grp1.nazwa = "grupaA";
        grp1.studenci = {stud1, stud2};

    struct group grp2;
        grp2.nazwa = "grupaB";
        grp2.studenci = {stud3, stud4};

    struct group grp3;
        grp3.nazwa = "grupaC";
        grp3.studenci = {stud5, stud6};

    vector<group> grupy = {grp1, grp2, grp3};

    cout << "grupaA przed dodaniem stud7:" << endl;
    for (int i = 0; i < grp1.studenci.size(); i++)
    {
        cout << grp1.studenci.at(i).name << " ";
    }
    cout << endl << endl;

    add_student_to_group(grp1 ,stud7);

    grp1.mediana_srednich = group_averages_median(grp1);
    grp2.mediana_srednich = group_averages_median(grp2);
    grp3.mediana_srednich = group_averages_median(grp3);

    cout << "grupaA po dodaniu stud7:" << endl;
    for (int i = 0; i < grp1.studenci.size(); i++)
    {
        cout << grp1.studenci.at(i).name << " ";
    }
    cout << endl << endl;

    cout << "Nazwa najlepszej grupy: " << best_groups_name(grupy) << endl;

    return 0;
}
