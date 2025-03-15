#include "Sequences/Sequences.h"

auto test = new int[5]{1, 2, 3, 4, 5};
auto test2 = new int[5]{5, 4, 3, 2, 1};

void testLinkedList() {
    std::cout << "--- Проверка ListSequence ---\n";
    // Связанный список
    auto *list = new LinkedList<int>();
    list->append(5);
    list->append(6);
    std::cout << "Создание СС и добавления 5 6 ->  ";
    list->print();

    Sequence<double> *Lls1 = new ListSequence<double>;
    Lls1->append(1.8);
    Lls1->append(1);

    Sequence<int> *Lls2 = new ListSequence(test, 5);
    Sequence<int> *Lls3 = new ListSequence(*list);

    Lls2->prepend(9);
    Lls3->insertAt(8, 1);
    std::cout << "Создание последовательности и добавление 1.8 1 -> ";

    Lls1->print();
    std::cout << "Создание последовательности на основе указателя {1 2 3 4 5} и добавление 9 в начало ->  ";

    Lls2->print();

    std::cout << "Создание последовательности на основе СС и вставка 8 на индекс 1 ->  ";

    Lls3->print();

    Lls2->getSubsequence(2, 5);
    std::cout << "ПодСписок от 2 до 5 - 2 3 4 ->  ";

    Lls2->print();
    std::cout << std::endl;
}

void testMutableArray() {
    std::cout << "--- Проверка MutableArraySequence ---\n";
    // Связанный список
    auto *list = new DynamicArray(test, 5);
    list->resize(3);
    std::cout << "Создание Дин массива и добавление ресайз до 3 элементов ->  ";
    list->print();

    Sequence<double> *Das1 = new MutableArraySequence<double>;
    Das1->append(1.8);
    Das1->append(1);

    Sequence<int> *Das2 = new MutableArraySequence(test, 5);
    Sequence<int> *Das3 = new MutableArraySequence<int>(*list);

    Das2->prepend(9);
    Das3->insertAt(8, 1);
    std::cout << "Добавление элементов - 1.8 1 -> ";

    Das1->print();
    std::cout << "Создание из указателя и добавленик в начало - 9 ->  ";

    Das2->print();

    std::cout << "Вставка в 1 индекс ->  ";

    Das3->print();

    Das2->getSubsequence(2, 5);
    std::cout << "ПодМассив от 2 до 5 - 2 3 4 ->  ";

    Das2->print();
    std::cout << std::endl;
}


void testImmutableArray() {
    std::cout << "--- Проверка ImmutableArraySequence ---\n";

    Sequence<int> *Das1 = new ImmutableArraySequence(test, 3);
    Das1->append(2);
    Das1->append(1);
    std::cout << "Добавление в неизменяемый массив - ничего не меняется ->  ";

    Das1->print();
    std::cout << "Но если сместить указатель на измененный ->  ";
    Das1 = Das1->append(2);
    Das1 = Das1->append(1);
    Das1->print();

    std::cout << std::endl;
}

int plus2(int a) {
    return a + 2;
}

bool del2(int a) {
    return a % 2 == 0;
}

int perm(int a, int b) {
    return a * b;
}

void testMore() {
    std::cout << "--- Проверка Дополнительных функций ---\n";


    Sequence<int> *seq = new MutableArraySequence(test, 5);
    std::cout << "Изначальный массив\n";
    seq->print();

    Sequence<int> *ans1 = map(&plus2, seq);
    std::cout << "Применение map с функцией +2: ";
    ans1->print();

    Sequence<int> *ans2 = where(&del2, ans1);
    std::cout << "Теперь возьмем только четные через where: ";
    ans2->print();

    int a = reduce(&perm, ans2, 1);
    std::cout << "Теперь перемножение всех элементов через reduce: " << a;
}

void testPolymorph() {
    std::cout << "--- Проверка перехода от типа к типу последовательности ---\n";

    Sequence<int> *ds = new MutableArraySequence(test, 5);
    Sequence<int> *ls = new ListSequence(test2, 5);
    Sequence<int> *ls_from_ds = new ListSequence<int>(*ds);

    Sequence<int> *ds_from_ls = new MutableArraySequence<int>(*ls);

    std::cout << "Сделаем из последовательности на массиве - списочную\n"
            "Было - на массиве ";
    ds->print();
    std::cout << "Стало - на списке ";
    ls_from_ds->print();
    std::cout << std::endl;
    std::cout << "Сделаем из последовательности на списке - массивную\n"
            "Было - на списке ";
    ls->print();
    std::cout << "Стало - на массиве ";
    ds_from_ls->print();
    std::cout << std::endl;

}

int del10(int a) {
    return a % 10;
}

void hardConcat() {
    Sequence<int> *s1 = new MutableArraySequence(new int[5]{1, 2, 3, 4, 5}, 4);
    Sequence<int> *s2 = new ListSequence(new int[5]{9, 88, 2}, 3);
    Sequence<int> *s3 = new MutableArraySequence(new int[8]{13, 12, 55, 35, 86, 12, 4, 4}, 5);
    Sequence<int> *s4 = new ListSequence<int>();

    auto all_seq = MutableArraySequence<Sequence<int> *>(new Sequence<int> *[3]{s3, s2, s1}, 3);
    std::cout << "--- Создадим 3 последовательности разных видов ---\n";

    for (int i = 0; i < all_seq.getSize(); i++) all_seq[i]->print();

    std::cout <<
            "Теперь добавим их всех в идиную последовательность последовательностей.\nА теперь пройдемся по ним for'ом и добавим в конец 0 и применим mod 10 через map\n";


    for (int i = 0; i < all_seq.getSize(); i++) {
        all_seq[i]->append(0);
        all_seq[i] = map(del10, all_seq[i]);
        all_seq[i]->print();
    }
    std::cout << "А теперь конкатенируем все подпоследовательности через reduce \n";

    const auto concat_seq = reduce(concat, &all_seq, s4);
    concat_seq->print();
    std::cout << std::endl;
}


void mainTest() {
    testLinkedList();
    testMutableArray();
    testImmutableArray();
    testMore();
    testPolymorph();
    hardConcat();
}
