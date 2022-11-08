#include "Appliances.h"
#include <algorithm>

void Appliances::write_end_file() {
    for (int i = 0; name[i]; i++)
        if (name[i] == ' ')
            name[i] = '.';
    for (int i = 0; type_of_appliences[i]; i++)
        if (type_of_appliences[i] == ' ')
            type_of_appliences[i] = '.';
	ofstream fout(name_file, ios::app);
	fout << id_product << " " << type_of_appliences << " " << name << " " << price << " " << quantity;
	fout << endl;
	fout.close();
}

void Appliances::write_end_file_type() {
    for (int i = 0; type_of_appliences[i]; i++)
        if (type_of_appliences[i] == ' ')
            type_of_appliences[i] = '.';
    ofstream fout(map_file, ios::app);
    fout << id_product << " " << type_of_appliences;
    fout << endl;
    fout.close();
}
void Appliances::upload_id() {
    ifstream fin(name_file, ios::in);
    string line;
    if (!fin) {
        cout << "Нет доступа к файлу,обратитесь к админу///";
    }
    else {
        while (getline(fin, line)) {
            id_product++;
        }
    }
    fin.close();
}
void Appliances::print_map() {
    load_from_file(arr_type);
    ShowTable table;
    table.add("Номер");
    table.add("Категория");
    table.endOfRow();
    for (auto& t : arr_type) {
        for (int i = 0; t.second[i]; i++)
            if (t.second[i] == '.')
                t.second[i] = ' ';
        table.add(to_string(t.first));
        table.add(t.second);
        table.endOfRow();
    }
    cout << table;
}

void Appliances::load_from_file(map<int, string>& arr_type) {
    ifstream f(map_file);
    int key;
    string temp;
    while (f >> key >> temp) {
        arr_type[key]=temp;
    }
    f.close();
}
void Appliances::load_from_file(vector<Appliances>& v) {
    ifstream f(name_file);
    Appliances temp;
    while (f >> temp) {
        v.push_back(temp);
    }
    f.close();
}
void Appliances::choose_type(int key) {
    type_of_appliences = arr_type[key];
}

void Appliances::add_product() {
    cout << "\t\t--> Добавление нового продукта <---" << endl;
    upload_id();
    print_map();
    cout << "Выберете категорию техники:";
    int choose;
    cin >> choose;
    choose_type(choose);
    cin.ignore();
    cout << "Введите название:";
    getline(cin, name);
    cout << "Введите цену:";
    cin >> price;
    cout << "Введите количество продоваемого товара:";
    cin >> quantity;
    cout << "Товар успешно добавлен!" << endl;
    write_end_file();
}
void Appliances::print_shop() {
    cout << "\t\t----> Перечень товаров в наличии <----" << endl;
    ShowTable t;
    t.add("Номер товара");
    t.add("Категория");
    t.add("Название");
    t.add("Цена");
    t.add("Количество");
    t.endOfRow();
    Appliances temp;
    ifstream fin(name_file, ios::in);
    while (fin >> temp) {
        t.add(to_string(temp.id_product));
        for (int i = 0; temp.type_of_appliences[i]; i++)
            if (temp.type_of_appliences[i] == '.')
                temp.type_of_appliences[i] = ' ';
        t.add(temp.type_of_appliences);
        for (int i = 0; temp.name[i]; i++)
            if (temp.name[i] == '.')
                temp.name[i] = ' ';
        t.add(temp.name);
        t.add(to_string(temp.price));
        t.add(to_string(temp.quantity));
        t.endOfRow();
    }
    fin.close();
    cout << t;
}

void Appliances::add_map() {
    cout << "\t\t~~~Добавление новой категории~~~" << endl;
    cout << "Введите номер" << endl;
    cin >> id_product;
    cout << "Введите категорию" << endl;
    getline(cin, type_of_appliences);
    cout << "Категория успешно добавлена" << endl;
    write_end_file_type();
}

void Appliances::edit_product() {
        load_from_file(arr_product);
        print_shop();
        int temp;
        cout << "Введите номер записи которую хотите изменить:";
        cin >> temp;
        int count = 0;
        int index;
        for (int i = 0; i < arr_product.size(); i++) {
            if (arr_product[i].id_product == temp) {
                count = 1;
                index = i;
                break;
            }
        }
        if (count == 0) {
            cout << "Записи с таким номером нет..." << endl;
        }
        system("cls");
        cout << "\t\t~~~Меню редактирования~~~" << endl;
        cout << "\t1.Редактировать категорию" << endl;
        cout << "\t2.Редактировать название" << endl;
        cout << "\t3.Редактировать количество" << endl;
        cout << "\t4.Редактировать цену" << endl;
        cout << "\t5.Назад" << endl;
        cout << "Ваш Выбор:";
        int choose;
        cin >> choose;
        switch (choose) {
        case 1: {
            cout << "Выберете новую категорию" << endl;
            print_map();
            int choose;
            cin >> choose;
            choose_type(choose);
            arr_product[index].type_of_appliences = type_of_appliences;

        }break;
        case 2: {
            cout << "Введите новое название" << endl;
            cin >> name;
            arr_product[index].name = name;
        }break;
        case 3: {
            cout << "Введите новое количество" << endl;
            cin >> quantity;
            arr_product[index].quantity = quantity;
        }break;
        case 4: {
            cout << "Введите новую цену" << endl;
            cin >> price;
            arr_product[index].price = price;
        }break;
        }
        ofstream onz(name_file);
        copy(arr_product.begin(), arr_product.end(), ostream_iterator<Appliances>(onz, "\n"));
        onz.close();
        arr_product.clear();
}

void Appliances::del_product() {
    vector<Appliances>tz;
    vector<Appliances>tk;
    load_from_file(tz);
    print_shop();
    int temp;
    cout << "Введите номер записи которую нужно удалить:";
    cin >> temp;
    int count = 0;
    for (int i = 0; i < tz.size(); i++) {
        if (tz[i].id_product != temp) {
            tk.push_back(tz[i]);
            ofstream onz(name_file);
            copy(tk.begin(), tk.end(), ostream_iterator<Appliances>(onz, "\n"));
            onz.close();
            count = 1;
        }
    }
    if (count == 0) {
        cout << "Записис с таким номером нет..." << endl;
    }
    else {
        cout << "Запись успешно удалена" << endl;
    }
    print_shop();
}
int checkInts()
{
    int value, counter = 0;
    char* BufForWriting = new char[256];
    cin.clear();
    cin.getline(BufForWriting, 256, '\n');
    for (int i = 0; BufForWriting[i] != '\0'; i++)
        if (isdigit(BufForWriting[i]))
            counter++;
    if (strlen(BufForWriting) != counter ||
        (BufForWriting[0] == '0' && strlen(BufForWriting) > 1))
        value = -1;
    else value = atoi(BufForWriting);
    delete[] BufForWriting;
    return value;
}

int checkIntervals(int min, int max)
{
    int value;
    value = checkInts();
    while (value < min || value > max)
    {
        cout << "Неккоректный ввод. Повторите попытку->";
        value = checkInts();
    }
    return value;
}

void Appliances::sort_product() {
    arr_product.clear();
    load_from_file(arr_product);
    vector<Appliances*> tz;
    for (auto item : arr_product) {
        tz.push_back(new Appliances(item.type_of_appliences, item.id_product, item.name, item.price, item.quantity));
    }
    cout << "\t\tМеню сортировки:" << endl;
    cout << "\t(1) ~ Отсортировать по номеру" << endl;
    cout << "\t(2) ~ Отсортировать по цене" << endl;
    cout << "\t(3) ~ Отсортировать по количеству" << endl;
    cout << "Ваш выбор: ";
    int what = checkIntervals(-3, 3);
    stable_sort(tz.begin(), tz.end(), comp_data(what));
    arr_product.clear();
    for (auto item : tz) {
        arr_product.push_back(*item);
    }
    ofstream onz(name_file);
    copy(arr_product.begin(), arr_product.end(), ostream_iterator<Appliances>(onz, "\n"));
    onz.close();
    arr_product.clear();
    print_shop();
}