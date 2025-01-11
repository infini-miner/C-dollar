Инструкция по применению компилятора и регистровой виртуальной машины C$ (Си-доллар, прежнее название Си-крюк).
-

Файлы для исходных кодов на ```C$``` используют расширение (формат) – `cdlr/sccdlr`, для откомпилированных в байт-код – `bccdlr`, в машинный/нативный код (AOT-компиляция) – `mccdlr/nccdlr` <br><br>
```VMC$``` реализован в виде: исполняемого файла (.exe), статической библиотеки (.lib/.a) и динамической библиотеки (.dll/.so). Управление процессами между игровым движком и ```VMC$``` происходит через ```API/FFI```.<br>
<br>
Три способа как можно объявить функцию, на которую будет передаваться управление потоком кода:
#
``` < Объявление функции и заполнение её содержимым (реализация) > ``` <br>
| Вариант | Исходный код: |
|---------|---------------|

| № | на английском | на русском |
|-|-|-
| ```1``` | ```ExecuteScript(){}```    | ```ВыполнитьСкрипт(){}```   |
| ```1``` | ```declare function ExecuteScript(){}``` | ```declare function ВыполнитьСкрипт(){}``` |

| ```1``` | ```(){}``` |
|-|-

Вы могли заметить, что можно создать функцию без имени. Но это так, будем считать подобное особенностью языка.<br>

При попытке скомпилировать такой файл, получите семантическую ошибку, о том, что данная конструкция является пустой и бессмысленной, т.к. внутри неё не оказалось ни одной вложенной инструкции.
По этой причине на выходе файл: ``` *.bccdlr ``` для ``` VMC$ ``` создан не будет.
Вам нужно внутри функции использовать хотя-бы одну инструкцию, чтобы скрипт оказался работоспособным.<br>

#
``` < Вызов функции > ``` <br>
| № | код на английском | код на русском |
|-|-|-
``` 1 ``` | ``` call function ExecuteScript(); ``` | ``` вызвать функцию ExecuteScript(); ``` <br>
``` 1 ``` | ``` ExecuteScript(); ``` | ``` ExecuteScript(); ```

| № | код |
|-|-
``` 1 ``` | ``` (); ``` <br>

#
``` < Однострочные комментарии > ``` <br>
| № | код на английском | код на русском |
|-|-|-|
```1``` | ```$ This is a one line comment``` | ```$ Это однострочный комментарий```<br>
```2``` | ```.. This is a one line comment``` | ```.. Это однострочный комментарий```<br>

#
``` < Встраиваемые однострочные комментарии: $=comment (могут применяться для описания аргументов у функций, когда их много) > ``` <br>

#
``` < Многострочные комментарии > ```
| № | код на английском | код на русском |
|-|-|-|
```1``` | ```<$``` | ```<$```<br>
```2``` | ```Multiline``` | ```Многострочный```<br>
```3``` | ```comment``` | ```комментарий```<br>
```4``` | ```$>``` | ```$>```<br>

#
``` < Вложенные многострочные комментарии (не рекомендуется использовать в большом количестве, из-за путоности) > ``` <br>
#
``` < Рекурсивный вызов функции > ```
<br>
| код на английском | код на русском |
|-|-|
| ```1``` ```$ This is not recommended``` | ```1``` ```$ Так не рекомендуется делать```
| ```2``` ```declare function ExecuteScript()``` | ```2``` ```объявить функцию ВыполнитьСкрипт()```
| ```3``` ```{``` | ```3``` ```{```
| ```4``` ```    call function ExecuteScript();``` | ```4``` ```    вызов функции ВыполнитьСкрипт();```
| ```5``` ```}``` | ```5``` ```}```

Байт-код сгенерирован не будет, вы получите семантическую ошибку об использовании рекурсии.
Рекурсия в программировании – это способ вызвать функцию внутри самой себя.
По умолчанию, в целях безопасности, компилятор будет выдавать ошибки при использовании рекурсии, дабы не опытным кодерам не наделать глупостей.
Если же вы всё таки хотите компилятору дать возможность обрабатывать рекурсию, задайте в его конфигурационном файле, в поле: ```recursive_function_call=``` – значение: ```enable``` или ```рекурсивный_вызов_функций=разрешить```, но будьте предельно осторожны, незабывая о необходимости создать условие для выхода из бесконечного вызова. Помните, лучше лишний раз избегать рекурсивные вызовы функций и использовать вместо них циклы, т.к. это гораздо эффективней и производительней.
Если после включения, захотите снова выключить рекурсию, используйте флаги состояний: ```disable``` или ```запретить```.<br>
<br>
В компиляторе блочные скобки используются по умолчанию, но вы при желании можете их отключить (параметр: ```block_brackets/блочные_скобки``` как раз за это и отвечает, со значением: ```do_not_display/не_отображать```) тогда ваш код станет более элегантным и чистым. Главное после этого быть внимательным к отступам, т.к. без скобок можно запутаться в логике кода.
#
< ``` Стиль чистого кода ``` >
| код на английском | код на русском |
|-|-|
| ```1``` ```$ Избавляемся от блочных скобочек``` | ```1``` ```$ Избавляемся от блочных скобочек```
| ```2``` ```declare function ExecuteScript()``` | ```2``` ```объявить функцию ВыполнитьСкрипт()```
| ```3``` ```    call function ExecuteScript();``` | ```3``` ```    вызов функции ВыполнитьСкрипт();```
#
< ``` Указатель на функцию ``` >
| код на английском | код на русском |
|-|-|
| ```1``` ```int addr = &ExecuteScript();``` | ```1``` ```цел адрес = &ВыполнитьСкрипт();```
| ```2``` ```int addr = ^ExecuteScript();``` | ```2``` ```цел адрес = ^ВыполнитьСкрипт();```
| ```3``` ```int addr = *ExecuteScript();``` | ```3``` ```цел адрес = *ВыполнитьСкрипт();```

Таким образом мы можем получить адрес функции (значение), сохранив его в целочисленную переменную.
#
< ``` Безусловный переход с использованием вычисляемого адреса (не константный) ``` >
| код на английском | код на русском |
|-|-|
| ```   1``` ```byte n = 0xFF;``` | ```   1``` ```байт знач = 0xFF;```
| ```   2``` ```goto n;``` | ```   2``` ```прыгнуть знач;```
| ```   3``` ```label 0xAA:``` | ```   3``` ```метка 0xAA:```
| ```1002``` ```label 0xFF:``` | ```1002``` ```метка 0xFF:```

| ```1003``` ```label ?:```|| ```1003``` ```метка ?:```
|-|-|-|

Применяется в тех случаях, когда сразу известно значение, к которому необходимо перейти. Это позволяет избавится от лишних последовательных проверок (работы CPU в холостую), тем самым - повысив производительность (при условии, что вы их используйте в очень большом количестве). Метки всегда должны быть уникальными (без дублирования). Если не будет соответствующего значения, он перейдёт на выполнение кода, идущее после 1002-й строчки кода (об этом позаботится компилятор, и автоматически подставит дополнительную метку, на случай невалидных значений).

#
< ``` Возврат значени-я(ий) счётчика из цикла ``` >
| № | C$ | C/C++
|-|-|-|
| ``` 1 ``` | ``` int j; ``` | ``` int j; ```
| ``` 2 ``` | ``` for (int i = 1; i != 1000; i ++) {}: j = i.{}; ``` | ``` for (int i = 1; i != 1000; i ++) { if (i == 1000) j = i; } ```
| ``` 3 ``` | ``` for (int i = j; i != 1; i --) {}: j = i.{}; ``` | ``` for (int i = j; i != 1; i --) { if (i == 1) j = i; } ```

В некоторых случаях может пригодиться вытащить значение счётчика (можно несколько, указав через запятую) из цикла находящегося в локальной области видимости. Посмотрите, как это удобно. Да и к тому лишний раз обходимся без доп. проверки на каждой итерации цикла. В следствии чего, прирост производительности.<br>
<br>

#
```[!] БЛИЖАЙШИЕ НОВОВВЕДЕНИЯ И ОБНОВЛЕНИЯ```<br>
<br>
``` < Индексация массивов, оператор индексации #defiarr, #defitrarr 0/1 (по умолчанию 1)> ``` <br>
``` < Создание, переименование и удаление локальных переменных с временем жизни > ``` <br>
``` < Область видимости переменных | инструкция `.{}`> ``` <br>
``` < Динамически выделяемая память на этапе компиляции (не путать с временем выполнения) > ``` <br>
``` < Строковые/текстовые регистры виртуальной машины для работы с динамически выделяемой памятью (организация менеджера памяти) > ``` <br>
``` < Использование унарного апострофа или пробела, для лучшей читабельности больших чисел > ``` <br>
``` < Ветвличный цикл (for/then if/then)> ``` <br>
``` < Запуск константных функций, описанных в виде данных: PerformFuncion(data); ``` <br>
#


---------------------
* Продолжение следует
---------------------
