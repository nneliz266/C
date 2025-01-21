#include<iostream>
#include<vector>
#include<cmath>
#include<iterator>
#include <algorithm>

/*
Сотовая связь
Вышка сотовой связи характеризуется координатами X и Y, а также радиусом зоны покрытия.
Качество сигнала определяется удаленностью мобильной станции от вышки.
Даны координаты абонента. Определить:
 1) Список базовых станций, с которыми может работать абонент (сформировать последовательность в виде вектора).
 2) Если расстояние до двух базовых станций одинаковое, то удалить ее из списка.
 3) Упорядочить базовые станции по качеству сигнала

 Входные данные:
 5
 A
 0 0 10
 B
 10 10 10
 C
 0 5 1
 D
 100 100 10
 E
 7 -7 7
 5 5
 */
struct Based_Station {
public:
    char m_name;
    int m_X, m_Y, m_R;

public:
    Based_Station()
        : m_name{ 'X' }, m_X{ 0 }, m_Y{ 0 }, m_R{ 0 }
    {}

    Based_Station(char name, int X, int Y, int R)
        :m_name{ name }, m_X{ X }, m_Y{ Y }, m_R{ R }
    {}

    float get_distance_to_user(int x, int y) const {
        return sqrt((x - m_X) * (x - m_X) + (y - m_Y) * (y - m_Y));
    }

};

std::ostream& operator<<(std::ostream& out, const Based_Station& bs) {
    return out << "BaseStation:\n name:" << bs.m_name << "\n X:" << bs.m_X << "\n Y:" << bs.m_Y << "\n R:" << bs.m_R;
}
/*5
a
0 0 10
b
10 10 10
c
0 5 1
d
100 100 10
e
7 -7 7
5 5
 
*/
struct Comparator {
public:
    int x, y;
public:
    Comparator(int X, int Y)
        :x{ X }, y{ Y }
    {}

    bool operator()(const Based_Station &l, const Based_Station &r) {
        return(l.get_distance_to_user(x, y) > r.get_distance_to_user(x, y)) ? false : true;
    }
};

/*bool comparator(Based_Station x, Based_Station y) {
    return(x.get_distance_to_user() > y.get_distance_to_user) ? false : true;
}*/



int main() {

    std::vector<char>stations_1{};
    int N;
    std::cin >> N;
    std::vector<Based_Station>stations(N);
    for (Based_Station& elem : stations) {
        std::cin >> elem.m_name >> elem.m_X >> elem.m_Y >> elem.m_R;
    }
    int x, y;
    std::cin >> x >> y;

    //    int j = 0;
    //    for (Based_Station &elem:stations) {
    //        if (elem.m_R >= elem.get_distance_to_user(x, y)) {
    //            stations_1.resize(j + 1, '0');
    //            stations_1[j] = elem.m_name;
    //            j++;
    //        }
    //    }
    //    for (char& elem : stations_1) {
    //        std::cout << elem;
    //    }





    Comparator comparator_{ x,y };
    std::sort(stations.begin(), stations.end(), comparator_);

    for (const Based_Station& bs : stations) {
        std::cout << bs << std::endl;
    }

    /*
    int j = 0;
    int x, y;
    std::cin >> x >> y;
    for (int i = 0; i < N; i++) {
        if (stations[i].m_R >= stations[i].get_distance_to_user(x, y)) {
            stations_1.resize(j + 1, '0');
            stations_1[j] = stations[i].m_name;
            j++;
        }
    }
    for (int i = 0; i < j; i++) {
        std::cout << stations_1[i];
    }*/




    //    for (int i = 0; i < N; i++) {
    //        for (int j = i + 1; j < N; j++) {
    //            if (i == j) {
    //                continue;}
    //            else if (stations[i].get_distance_to_user(x, y) > stations[j].get_distance_to_user(x, y)) {
    //                std::swap(stations[i], stations[j]);
    //            }
    //        }
    //    }
    //    for (Based_Station& elem : stations) {
    //        std::cout << elem.m_name;
    //    }


    return 0;

}