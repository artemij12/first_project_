u_int count_of_rotation = 0;//количество прерываний оптопары (ввел псевдоним u_int это unsigned int) 
float time_of_rotation = 0;//время прерывания оптопары
byte mode; //текущий пункт меню, хотя их у нас пока 2, но потом можем расширять, byte это unsigned char
float litres=0.0; //количество литров, что будет выводиться на экран (можети не понадобится)
enum rezhim
{
ust=U, work=W,reset=R
};//перечисляемый тип устанавливаем в работу 
setup()
{
pinMode(2,INPUT);//установка ножки камня на чтение сигналов из оптопары

}
byte pusk_push()// в эту функцию можно передать значение счетчика (для разных камней разная выдержка будет short pusk_push(short t), но пока смысла нет,камень один 
{
  
//Если клавиша нажата долго возвращем например 1 , т.е. счетчик досчитал до конца 
//если нажата не долго 2
// считываем уровня сигнала на пине, если низкий сразу возвращаем 0
}
bool push_set()
{
//считываем уровня сигнала на пине, если низкий сразу возвращаем False , иначе True
//При нажатии меняем переменную R на другую перчисляемую
}
void print_char(byte c)// функция печати пункта меню
{
// Взависимости от значения с выводим на экран U/W/R(резет потом скидываем и вовращаемся в режим W)
}
void print_cyf(byte i)
{
//Функция вывода на экран цифр, выводим i переведя его в строку 
}
void start_inr() //устанавливаем прерывание , данные берем из setup.h
{
}
void stop_inr() // убираем прерывание....Можно конечно и в цикле loop все это написать, но функциями сподручнее
{
}
void count_and_time_rot(){
//в этой функции будет реализован подсчет количества оборотов крыльчатки и времени, на которое прерывается оптопара
}
loop ()
{
  if (push_set()==TRUE){//если кнопка нажата один раз,то начинают выводиться режимы работы прибора
    print_char(); // начинаем вывод режимов работы
    if (print_char()=="U"&&push_set()==TRUE){//если режим выбирается нужный режим работы и наживается кнопка set, то начинается увеличение объема воды для юстировки
      while(push_set()==TRUE){ // пока кнопка зажата объем жидкости для юстировки увеличивается
        print_cyf();
      }//конец вывода объема воды достигается при отпускании кнопки SET
      if(f_reset()==FALSE){//если кнопка пуск/стоп зажата долго, то в функцию вывода объема воды передается отрицательное значение и счетчик сбрасывается до 0
        print_cyf();
      }
    if(push_pusk()==2){ // если происходит кратковременное нажатие кнопки пуск она же стоп, то начинается пролив жидкости и подсчет времени и количества прерываний оптопары
      count_and_time_rot();            
    }
    save_rez();
    }
    else if(print_char()=="R"&&push_set()==TRUE){
      if (push_pusk()==2){
        speed_calc();// немного не понял, что означает фраза "данная функция вызывается по прерыванию", но оставлю свое видение, что если происходит кратковременное нажатие кнопки пуск(стоп)
        rezult();    // то начинается сразу же подсчет проливаемой жидкости и после ее выполнения будет идти функция для вывода результата измерений
      }
    }
    else if(print_char()=="Res"&&push_set()==TRUE){
      if (f_reset()==FALSE){
        if(reset_save_rez()==TRUE){//очистка таблицы в EEPROM
        print_rez_of_reset_1();
      }
        else  if(reset_save_rez()==TRUE){//очистка таблицы в EEPROM
        print_rez_of_reset_2();
      }
    }
  }
 }
}
  
//здесь реализуем бесконечный цикл обработки нажатий клавиш
// тут будет простая лесенка операторов выбора вида if push_set() { ....} else
// или в принципе switch...case... еще удобно делать бесконечные циклы типа while True с выходом по break; Ни кто не мешает комбинировать
// так же напомню, что в Си 0 это False, любое отрицательное число False , также очень удобны конструкции типа if push_pusk()&&R==work {...}
// тут логическое И применяется к двум результатам возвращаемого значения функции pusk_push() и результат сравнения переменной R с перечисляемым типом
}
bool f_reset(u_int t) // функция зажима клавиши Пуск/Стоп длинное зажатие будет означать FALSE т.е. сброс значений неважно чего
{
// здесь реализован счетчик, ну или если захочется очень))) установка и обработка прерывания, если нужное время прошло клавиша зажата return True
}
short speed_calc()//она должна уже возвращать количество литров
{
//эта функция вызывается по прерыванию, когда тикнул таймер, она высчитывает на основании глобальных пременных объявленных в setup() количество вращений крыльчатки и затем
// она берет данные юстировки, где известно, что определенное количество оборотов крыльчатки соответсвует определенному количеству жидкости прошедшей через трубу
//таких функций можно наделать много и матаппарат еще придется допиливать напильником, но он простой....и чем больше таких функций, тем точнее будет матмодель  
//пока надо сделать грубую модель, а вот ее улучшать как мне видится можно математикой
}
void rezult(){
// вывод результата измерений объема жидкости
}
void math_model(....)// это штука на будущее...отдельно от обработчиков надо создать матмодель, в которую мы передаем данные (скорей всего в структурах struct) и она уже считает все как надо
void save_rez(short ob, short kolvj, short koeff)
{
создаем условную табличку в EEPROM...Упакованную ...2 байта на каждую переменную...Читать легко, записывать еще проще..
}
bool reset_save_rez(){
//очистка значений таблицы юстировки логический тип возвращаемого значения нужен для того, чтобы вывести результат работы функции и вывести его на экран 
}
void rint_rez_of_reset_1(){
//вывод надписи об успешной очистке EEPROM
}
void rint_rez_of_reset_2(){
//вывод надписи в случае не успешной очистки EEPROM
}
// Это пока в общих чертах на сутках накидал на листочке(так лучше думается )))) и перебил в цифру...Это еще просто наработка....Вообще если под один камень писать, тут есть где разгуляться ассму...
//Но лучше Си....масштабируемость даже близко не сравнима
