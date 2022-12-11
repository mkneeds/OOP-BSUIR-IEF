#include "Shop.h"
#include <algorithm>

void OnlineShop::write_end_file() {
    for (int i = 0; name[i]; i++)
        if (name[i] == ' ')
            name[i] = '.';
    for (int i = 0; type[i]; i++)
        if (type[i] == ' ')
            type[i] = '.';
    ofstream fout(name_file, ios::app);
    fout << id_product << " " << type << " " << name << " " << price << " " << quantity;
    fout << endl;
    fout.close();
}

void OnlineShop::write_end_file_type() {
    for (int i = 0; type[i]; i++)
        if (type[i] == ' ')
            type[i] = '.';
    ofstream fout(map_file, ios::app);
    fout << id_product << " " << type;
    fout << endl;
    fout.close();
}
void OnlineShop::write_end_file_q(string name,string number,string prior) {

    ofstream fout("Queue.txt", ios::app);
    fout << name << " " << number << " "<<prior;
    fout << endl;
    fout.close();
}

void OnlineShop::upload_id() {
    ifstream fin(name_file, ios::in);
    string line;
    if (!fin) {
        cout << "��� ������� � �����,���������� � ������///";
    }
    else {
        while (getline(fin, line)) {
            id_product++;
        }
    }
    fin.close();
}
void OnlineShop::print_map() {
    load_from_file(arr_type);
    ShowTable table;
    table.add("�����");
    table.add("���������");
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

void OnlineShop::load_from_file(map<int, string>& arr_type) {
    ifstream f(map_file);
    int key;
    string temp;
    while (f >> key >> temp) {
        arr_type[key] = temp;
    }
    f.close();
}
void OnlineShop::load_from_file(vector<OnlineShop>& v) {
    ifstream f(name_file);
    OnlineShop temp;
    while (f >> temp) {
        v.push_back(temp);
    }
    f.close();
}
void OnlineShop::choose_type(int key) {
    type = arr_type[key];
}

void OnlineShop::add_product() {
    cout << "\t\t--> ���������� ������ ������ <---" << endl;
    upload_id();
    print_map();
    cout << "�������� ��� ������:";
    int choose;
    cin >> choose;
    choose_type(choose);
    cin.ignore();
    cout << "������� ��������:";
    getline(cin, name);
    cout << "������� ����:";
    cin >> price;
    cout << "������� ���������� ������������ ������:";
    cin >> quantity;
    cout << "����� ������� ��������!" << endl;
    write_end_file();
}

void OnlineShop::print_shop() {
    cout << "\t\t----> �������� ������� � ������� <----" << endl;
    ShowTable t;
    t.add("����� ������");
    t.add("���");
    t.add("��������");
    t.add("����");
    t.add("����������");
    t.endOfRow();
    OnlineShop temp;
    ifstream fin(name_file, ios::in);
    while (fin >> temp) {
        t.add(to_string(temp.id_product));
        for (int i = 0; temp.type[i]; i++)
            if (temp.type[i] == '.')
                temp.type[i] = ' ';
        t.add(temp.type);
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

void OnlineShop::add_map() {
    cout << "\t\t~~~���������� ������ �����~~~" << endl;
    cout << "������� �����" << endl;
    cin >> id_product;
    cout << "������� ����" << endl;
    getline(cin, type);
    cout << "����� ���� ������� �������� � ���� " << endl;
    write_end_file_type();
}

void OnlineShop::edit_product() {
    load_from_file(arr_product);
    print_shop();
    int temp;
    cout << "������� ����� ������ ������� ������ ��������:";
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
        cout << "������ � ����� ������� ���..." << endl;
    }
    system("cls");
    cout << "\t\t~~~���� ��������������~~~" << endl;
    cout << "\t1.������������� ����" << endl;
    cout << "\t2.������������� ��������" << endl;
    cout << "\t3.������������� ����������" << endl;
    cout << "\t4.������������� ����" << endl;
    cout << "\t5.�����" << endl;
    cout << "��� �����:";
    int choose;
    cin >> choose;
    switch (choose) {
    case 1: {
        cout << "�������� ����� ����" << endl;
        print_map();
        int choose;
        cin >> choose;
        choose_type(choose);
        arr_product[index].type = type;

    }break;
    case 2: {
        cout << "������� ����� ��������" << endl;
        cin >> name;
        arr_product[index].name = name;
    }break;
    case 3: {
        cout << "������� ����� ����������" << endl;
        cin >> quantity;
        arr_product[index].quantity = quantity;
    }break;
    case 4: {
        cout << "������� ����� ����" << endl;
        cin >> price;
        arr_product[index].price = price;
    }break;
    }
    ofstream onz(name_file);
    copy(arr_product.begin(), arr_product.end(), ostream_iterator<OnlineShop>(onz, "\n"));
    onz.close();
    arr_product.clear();
}

void OnlineShop::del_product() {
    vector<OnlineShop>tz;
    vector<OnlineShop>tk;
    load_from_file(tz);
    print_shop();
    int temp;
    cout << "������� ����� ������ ������� ����� �������:";
    cin >> temp;
    int count = 0;
    for (int i = 0; i < tz.size(); i++) {
        if (tz[i].id_product != temp) {
            tk.push_back(tz[i]);
            ofstream onz(name_file);
            copy(tk.begin(), tk.end(), ostream_iterator<OnlineShop>(onz, "\n"));
            onz.close();
            count = 1;
        }
    }
    if (count == 0) {
        cout << "������ � ����� ������� ���..." << endl;
    }
    else {
        cout << "������ ������� �������" << endl;
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
        cout << "������������ ����. ��������� �������->";
        value = checkInts();
    }
    return value;
}

void OnlineShop::sort_product() {
    arr_product.clear();
    load_from_file(arr_product);
    vector<OnlineShop*> tz;
    for (auto item : arr_product) {
        tz.push_back(new OnlineShop(item.type, item.id_product, item.name, item.price, item.quantity));
    }
    cout << "\t\t���� ����������:" << endl;
    cout << "\t(1) ~ ������������� �� ������" << endl;
    cout << "\t(2) ~ ������������� �� ����" << endl;
    cout << "\t(3) ~ ������������� �� ����������" << endl;
    cout << "��� �����: ";
    int what = checkIntervals(-3, 3);
    stable_sort(tz.begin(), tz.end(), comp_data(what));
    arr_product.clear();
    for (auto item : tz) {
        arr_product.push_back(*item);
    }
    ofstream onz(name_file);
    copy(arr_product.begin(), arr_product.end(), ostream_iterator<OnlineShop>(onz, "\n"));
    onz.close();
    arr_product.clear();
    print_shop();
}
void OnlineShop::add_people() {
    cout << "������� ��� �������" << endl;
    string name;
    cin >> name;
    cout << "������� ����� ��������" << endl;
    string number;
    cin >> number;
    cout << "������������ �� ������?(��/���)" << endl;
    string priority;
    cin >> priority;
    write_end_file_q(name, number,priority);
    ifstream f("Queue.txt");
    int counts = 0;
     while (getline(f,name)) {
         counts++;
     }
     f.close();
     cout << "�� ����� � �������->" << counts;
}
void OnlineShop::print_que() {
    ifstream f("Queue.txt");
    int counts = 0;
    string name, nummer, priors;
    while (f>>name>>nummer>>priors) {
        if (priors == "��") {
            prior.push(name);
        }
        else {
            que.push(name);
        }
    }
    f.close();
    cout << "����� �� ������ ��������� ���� ��������:" << endl;
    for (auto i = 0; i < prior.size(); i++) {
        cout<<i<<"-"<<prior.top()<<endl;
    }
    cout << "����� ����:" << endl;
    for (auto i = 0; i < prior.size(); i++) {
        cout << i << "-" << que.front() << endl;
    }
}

void OnlineShop::buy_product(int balance) {
    print_shop();
    arr_product.clear();
    load_from_file(arr_product);
    int temp;
    cout << "������� ����� ������ ������� ������ ������:";
    cin >> temp;
    int count = 0;
    int index;
    for (int i = 0; i < arr_product.size(); i++) {
        if (arr_product[i].id_product == temp) {
            count = 1;
            index = i;
            break;
            stac.push(arr_product[i].id_product);
        }
    }
    if (count == 0) {
        cout << "������ � ����� ������� ���..." << endl;
    }

    cout << "������� ���������� ������,�������� ������ ������" << endl;
    int cou;
    cin >> cou;
    if (cou * arr_product[index].price <= balance) {
        cout << "������� ������ �������!" << endl;
        cout << "� ������ ������� ������� ->" << cou * arr_product[index].price << "�." << endl;
        schet = cou * arr_product[index].price;
        arr_product[index].quantity -= cou;
        ofstream onz(name_file);
        copy(arr_product.begin(), arr_product.end(), ostream_iterator<OnlineShop>(onz, "\n"));
        onz.close();
        cout << "\t\t������ �������� ���?" << endl;
        cout << "1)��" << endl;
        cout << "2)���" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
        case 1: {
            ShowTable t;
            t.add("~~~~~~~���~~~~~~~");
            t.add("");
            t.endOfRow();
            t.add("�������� ��������");
            t.add(arr_product[index].name);
            t.endOfRow();
            t.add("�������(��):");
            t.add(to_string(cou));
            t.endOfRow();
            t.add("� ������:");
            t.add(to_string(schet));
            t.endOfRow();
            cout << t;
            ofstream otchet("Otchet.txt");
            otchet << t;
            otchet.close();
            system("Otchet.txt");
        }
        case 2: break;
        }
    }
    else {
        cout << "������������ �������" << endl;
    }
}