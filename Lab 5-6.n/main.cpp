#include <iostream>
#include <iomanip>
using namespace std;
class Animal {
private:
    char* name;
    int limbs;
    int chromos;
    double weight;
    int hab;
    static int hab1, hab2, hab3, hab4;
    static double countlimbs, countanimals;
public:
    // Конструктор без параметров, присваивает полям limbs, chromos, weight значение
    Animal() {
        limbs = 0;
        chromos = 0;
        weight = 0;

    }
    // Конструктор с параметрами
    Animal(const char * nname, int nlimbs, int nchromos, double nweight, int nhab) {
        name = new char[256];
        giveName(nname);
        giveLimbs(nlimbs);
        giveChromos(nchromos);
        giveWeight(nweight);
        giveHab(nhab);
    }
    // Конструктор копирования
    Animal (const Animal & other) {
        for (int i = 0; i < 256; i++) {
            name[i] = other.name[i];
        }
        limbs = other.limbs;
        chromos = other.chromos;
        weight = other.weight;
        hab = other.hab;
    }
    // Деструктор для очищения памяти, выделенной для массива символов
    ~Animal() {
        delete [] name;
    }
    void outputName() {
        cout << "Название животного - " << name << endl;
    }
    void outputLimbs() {
        cout << "Количество конечностей - " << limbs << endl;
    }
    void outputChromos() {
        cout << "Количество хромосом - " << chromos << endl;
    }
    void outputWeight() {
        cout << "Вес - " << weight << " кг" << endl;
    }
    void outputHab() {
        if (hab == 1) {
            cout << "Среда обитания - наземно-воздушная" << endl;
        }
        if (hab == 2) {
            cout << "Среда обитания - водная" << endl;
        }
        if (hab == 3) {
            cout << "Среда обитания - почвенная" << endl;
        }
        if (hab == 4) {
            cout << "Среда обитания - другое" << endl;
        }
    }
    void giveName(const char * nname) {
        for (int i = 0; i < 256; i++) {
            if (nname[i] != '\0') {
                name[i] = nname[i];
            } else {
                break;
            }
        }
    }
    void giveLimbs(int nlimbs) {
        limbs = nlimbs;
    }
    
    void giveChromos(int nchromos) {
        chromos = nchromos;
    }
    void giveWeight(double nweight) {
        weight = nweight;
    }
    void giveHab(int nhab) {
        hab = nhab;
        if (nhab == 1) {
            hab1++;
        }
        if (nhab == 2) {
            hab2++;
        }
        if (nhab == 3) {
            hab3++;
        }
        if (nhab == 4) {
            hab4++;
        }
    }
    int getChromos() {
        return chromos;
    }
    const char* getName() {
        return name;
    }
    int getLimbs() {
        return limbs;
    }
    double getWeight() {
        return weight;
    }
    static void infoHab() {
        cout << "Количество животных, обитающих в наземно-воздушной среде: " << hab1 << endl;
        cout << "Количество животных, обитающих в водной среде: " << hab2 << endl;
        cout << "Количество животных, обитающих в почве: " << hab3 << endl;
        cout << "Количество животных, обитающих в другой среде: " << hab4 << endl;
    }
    static bool compare(int ch1, int ch2) {
        return ch1 > ch2;
    }
    static void infoChromo(Animal* arr[], int length) {
        for (int i = 0; i < length - 1; i++) {
            int minIndex = i;
            
            for (int j = i + 1; j < length; j++) {
                if (compare(arr[minIndex]->getChromos(),arr[j]->getChromos())) {
                    minIndex = j;
                }
            }
            Animal* temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            
        }
        for (int i = 0; i < length; i++) {
            cout << "Название животного - " << arr[i]->getName() << ". Число хромосом - " << arr[i]->getChromos() << endl;
        }
    }
    static double infoAverage(Animal* arr[], int length, int m) {
        for (int i = 0; i < length; i++) {
            if ((arr[i]->getWeight()) < m) {
                countanimals++;
                countlimbs += (arr[i]->getLimbs());
            }
        }
        return (countanimals != 0)? countlimbs/countanimals : 0;
    }
    
};

int Animal::hab1 = 0;
int Animal::hab2 = 0;
int Animal::hab3 = 0;
int Animal::hab4 = 0;
double Animal::countlimbs = 0;
double Animal::countanimals= 0;

int main() {
    cout << setprecision(14) << fixed;
    char* name = new char[256];
    int limbs, chromos;
    double weight;
    int hab;
    cout << "Введите название животного: ";
    cin >> name;
    cout << endl;
    cout << "Введите количество конечностей: ";
    cin >> limbs;
    cout << endl;
    cout << "Введите количество хромосом: ";
    cin >> chromos;
    cout << endl;
    cout << "Введите вес (в кг): ";
    cin >> weight;
    cout << endl;
    cout << "Если среда обитания животного наземно-воздушная, введите число 1, если среда обитания - водная, введите число 2, если среда обитания - почва, введите число 3, в противных случаях введите число 4: ";
    cin >> hab;
    cout << endl;
    Animal Animal1(name, limbs, chromos, weight, hab);
    delete [] name;
    
    Animal1.outputName();
    Animal1.outputLimbs();
    Animal1.outputChromos();
    Animal1.outputWeight();
    Animal1.outputHab();
    cout << endl;
    
    Animal Mouse("Мышь", 4, 20, 0.03, 1);
    Animal Mole ("Крот", 4, 35, 0.17, 3);
    Animal Giardia("Лямблия", 8, 1, 0.00000000012, 4);
    Animal Carp ("Карп", 0, 104, 12, 2);
    Animal Gopher("Суслик", 4, 36, 1.5, 3);
    Animal Crocodile("Крокодил", 4, 32, 700.5, 2);
    Animal Leopard("Леопард", 4, 38, 25, 1);
    
    Animal::infoHab();
    
    int length2 = 8;
    Animal* arr2[] = {&Animal1, &Mouse, &Mole, &Giardia, &Carp, &Gopher, &Crocodile, &Leopard};
    // передаём ссылку на объекты класса, так как нам не нужно их изменять,только посмотреть, что там есть
    cout << endl;
    Animal::infoChromo(arr2, length2);
    cout << endl;
    
    int length3 = 8;
    Animal* arr3[] = {&Animal1, &Mouse, &Mole, &Giardia, &Carp, &Gopher, &Crocodile, &Leopard};
    int m;
    cout << "Введите вес, ниже которого хотите рассчитать среднее количество конечностей у животных: ";
    cin >> m;
    cout << Animal::infoAverage(arr3, length3, m) << endl;
    return 0;
}
