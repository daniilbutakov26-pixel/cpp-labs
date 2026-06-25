#include <iostream>
#include <string>

using namespace std;

// =======================================================
// ЛАБОРАТОРНАЯ РАБОТА 10
// Односвязный линейный список.
// Задача: учёт автобусов в парке и на маршруте.
// =======================================================


// =======================================================
// СТРУКТУРА ДАННЫХ ОБ АВТОБУСЕ
// =======================================================

struct Bus
{
    int busNumber;        // номер автобуса
    string driverName;    // фамилия и инициалы водителя
    int routeNumber;      // номер маршрута
};


// =======================================================
// ШАБЛОН КЛАССА ОДНОСВЯЗНОГО СПИСКА
// =======================================================

template <class T>
class SingleList
{
private:
    // Узел односвязного списка
    struct Node
    {
        T data;       // данные узла
        Node* next;   // указатель на следующий узел
    };

    Node* head;       // начало списка

public:
    // Конструктор создаёт пустой список
    SingleList()
    {
        head = nullptr;
    }

    // Деструктор очищает память
    ~SingleList()
    {
        clear();
    }

    // Проверка пустого списка
    bool isEmpty() const
    {
        return head == nullptr;
    }

    // Добавление элемента в конец списка
    void pushBack(const T& value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }

    // Удаление элемента по номеру автобуса.
    // Если элемент найден, он удаляется из текущего списка,
    // а его данные возвращаются через removedValue.
    bool removeByBusNumber(int number, T& removedValue)
    {
        if (head == nullptr)
            return false;

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr)
        {
            if (current->data.busNumber == number)
            {
                removedValue = current->data;

                // Если удаляется первый элемент
                if (previous == nullptr)
                    head = current->next;
                else
                    previous->next = current->next;

                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    // Поиск элемента по номеру автобуса
    bool findByBusNumber(int number, T& foundValue) const
    {
        Node* current = head;

        while (current != nullptr)
        {
            if (current->data.busNumber == number)
            {
                foundValue = current->data;
                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Вывод всех элементов списка
    void print(const string& title) const
    {
        cout << "\n" << title << endl;

        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        while (current != nullptr)
        {
            cout << "Bus number: " << current->data.busNumber << endl;
            cout << "Driver: " << current->data.driverName << endl;
            cout << "Route: " << current->data.routeNumber << endl;
            cout << "--------------------------" << endl;

            current = current->next;
        }
    }

    // Очистка списка
    void clear()
    {
        Node* current = head;

        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
    }
};


// =======================================================
// ВВОД ДАННЫХ ОБ АВТОБУСЕ
// =======================================================

Bus inputBus()
{
    Bus bus;

    cout << "Enter bus number: ";
    cin >> bus.busNumber;

    cin.ignore();

    cout << "Enter driver name: ";
    getline(cin, bus.driverName);

    cout << "Enter route number: ";
    cin >> bus.routeNumber;

    return bus;
}


// =======================================================
// ГЛАВНАЯ ФУНКЦИЯ
// =======================================================

int main()
{
    SingleList<Bus> parkList;   // список автобусов в парке
    SingleList<Bus> routeList;  // список автобусов на маршруте

    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << "LABORATORY WORK 10\n";
        cout << "1 - Add bus to park\n";
        cout << "2 - Send bus from park to route\n";
        cout << "3 - Return bus from route to park\n";
        cout << "4 - Show buses in park\n";
        cout << "5 - Show buses on route\n";
        cout << "6 - Find bus\n";
        cout << "0 - Exit\n";
        cout << "Choose action: ";
        cin >> choice;

        if (choice == 1)
        {
            // Начальное формирование данных обо всех автобусах в парке
            Bus bus = inputBus();
            parkList.pushBack(bus);

            cout << "Bus added to park." << endl;
        }
        else if (choice == 2)
        {
            // Выезд автобуса из парка на маршрут
            int number;
            Bus bus;

            cout << "Enter bus number: ";
            cin >> number;

            if (parkList.removeByBusNumber(number, bus))
            {
                routeList.pushBack(bus);
                cout << "Bus moved from park to route." << endl;
            }
            else
            {
                cout << "Bus not found in park." << endl;
            }
        }
        else if (choice == 3)
        {
            // Въезд автобуса с маршрута обратно в парк
            int number;
            Bus bus;

            cout << "Enter bus number: ";
            cin >> number;

            if (routeList.removeByBusNumber(number, bus))
            {
                parkList.pushBack(bus);
                cout << "Bus returned from route to park." << endl;
            }
            else
            {
                cout << "Bus not found on route." << endl;
            }
        }
        else if (choice == 4)
        {
            // Вывод сведений об автобусах, находящихся в парке
            parkList.print("BUSES IN PARK:");
        }
        else if (choice == 5)
        {
            // Вывод сведений об автобусах, находящихся на маршруте
            routeList.print("BUSES ON ROUTE:");
        }
        else if (choice == 6)
        {
            // Поиск автобуса сначала в парке, затем на маршруте
            int number;
            Bus bus;

            cout << "Enter bus number: ";
            cin >> number;

            if (parkList.findByBusNumber(number, bus))
            {
                cout << "\nBus found in park." << endl;
                cout << "Driver: " << bus.driverName << endl;
                cout << "Route: " << bus.routeNumber << endl;
            }
            else if (routeList.findByBusNumber(number, bus))
            {
                cout << "\nBus found on route." << endl;
                cout << "Driver: " << bus.driverName << endl;
                cout << "Route: " << bus.routeNumber << endl;
            }
            else
            {
                cout << "Bus not found." << endl;
            }
        }
        else if (choice == 0)
        {
            cout << "Exit." << endl;
        }
        else
        {
            cout << "Wrong action." << endl;
        }

    } while (choice != 0);

    system("pause");

    return 0;
}
