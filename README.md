Инструкция по применению компилятора и виртуальной машины C$ (Си-доллар, прежнее название Си-крюк).
-
Язык программирования ```С$``` был придуман в целях написания сценариев (особенно хорошее применение найдёт в геймдеве).
Можно рассматривать как альтернативу и замену – Pawn (устаревший и малофункциональный) с Lua (не Си-подобный).
В языке имеется много всяких штуковин, которых нет в том же Pawn/Lua и прочих языках, которые были бы полезны при разработке проектов с огромной кодовой базой.

Файлы для исходных кодов на ```C$``` используют расширение (формат) – `cdlr`, для откомпилированных в байт-код – `bccdlr` <br><br>
Точка выполнения скрипта начинается с создания основной функции. Есть два стандартных подхода к этому: <br>

1.: придумываем любое название для функции (обычно не применяется на практике);<br>
2.: название для функции соответствует имени файла (часто применимо на практике);<br>
<br>
В обоих случаях расположение функции должно быть в самом начале скрипта. <br>

| Вариант | Исходный код: |
|---------|---------------|

| № | на английском | на русском |
|---------|---------------|------------|
| ```1``` | ```1``` ```ExecuteScript(){}```    | ```1``` ```ВыполнитьСкрипт(){}```   |
| ```2``` | ```1``` ```declare function ScriptEntryPoint(){}``` | ```1``` ```объявить функцию точкаВходаВскрипт(){}``` |
| ```3``` | ```1``` ```declare function Script(){}```           | ```1``` ```объявить функцию Скрипт(){}```            |

| ```4``` | ```1``` ```(){}``` |
|---------|---------------|

Исходя из того, что функции выполняют какие-либо действия, то и названия у них должны быть соответствующие. На мой взгляд, первый вариант можно считать самым подходящим.<br>
<br>
В последнем варианте создаётся функция не имеющая названия.
Такие функции принято называть безымянными.
Вызываются они особым методом. Более конкретно для чего это нужно, вы узнаете чуть позже.
Ну а пока сам вызов делается так:<br>

< файл: ```0.cdlr``` (исходный код на языке ```C$```)>
<br>
| код на английском | код на русском |
|-|-|
```1``` ```call function ExecuteScript();``` | ```1``` ```вызвать функцию ExecuteScript();```<br>
```1``` ```ExecuteScript();``` | ```1``` ```ExecuteScript();```

<br>
Скрипт всегда начинается с основной функции, которую надо определить самим. Ниже показан пример как это сделать. <br<br>

< файл: ```0.cdlr``` (исходный код на языке ```C$```)>
<br>
| код на английском | код на русском |
|-|-|
```1``` ```declare function ExecuteScript(){}``` | ```1``` ```объявить функцию ВыполнитьСкрипт(){}```<br>
```1``` ```ExecuteScript(){}``` | ```1``` ```ВыполнитьСкрипт(){}```
<br>

При попытке скомпилировать такой файл, получите семантическую ошибку, о том, что данная конструкция является пустой и бессмысленной, т.к. внутри неё не оказалось ни одной вложенной инструкции.
По этой причине на выходе файл: ```0.bccdlr``` для ```VM-C$``` создан не будет.
Вам нужно внутри функции использовать хотя-бы одну инструкцию, чтобы скрипт оказался работоспособным.<br>

#
``` < Однострочные комментарии > ``` <br>
| № | код на английском | код на русском |
|-|-|-|
```1``` | ```$ This is a one line comment``` | ```$ Это однострочный комментарий```<br>
```2``` | ```.. This is a one line comment``` | ```.. Это однострочный комментарий```<br>
```3``` | ```// This is a one line comment``` | ```// Это однострочный комментарий```<br>
```4``` | ```# This is a one line comment``` | ```# Это однострочный комментарий```<br>

В скором времени могут быть вырезаны: 3-й вариант на 50% и 4-й вариант на 75%. 3-й вариант был добавлен по причине его использования в Си-подобных языках.<br>

< Тема: ```Встраиваемые однострочные комментарии``` (могут применяться для описания аргументов у функций, когда их много), файл: ```0.cdlr``` (исходный код на языке ```C$```)><br>
| код на английском | код на русском |
|-|-|
```1``` ```$ Below is an example of inline one-line comments.``` | ```1``` ```$ Ниже приведен пример встроенных однострочных комментариев```<br>
```2``` ```call function SetVehicleParams($is the engine running=false, $are the doors open=true)``` | ```2``` ```вызвать функцию УстановитьТранспортуПараметры($двигатель работает=ложь, $двери открыты=истина)```<br>
```3``` ```$ It is possible this way . . .``` | ```3``` ```$ Можно таким способом . . .```<br>
```4``` ```call function SetVehicleParams($is the engine running:false, $are the doors open:true)``` | ```4``` ```вызвать функцию УстановитьТранспортуПараметры($двигатель работает:ложь, $двери открыты:истина)```<br>

В скором времени может быть вырезан: 4-й вариант на 50%.<br>

#
``` < Многострочные комментарии > ```
| № | код на английском | код на русском |
|-|-|-|
```1``` | ```<$``` | ```<$```<br>
```2``` | ```Multiline``` | ```Многострочный```<br>
```3``` | ```comment``` | ```комментарий```<br>
```4``` | ```$>``` | ```$>```<br>

#
``` < Вложенные многострочные комментарии (не рекомендуется использовать в большом количестве, из-за путоности) > ```
| № | код на английском | код на русском |
|-|-|-|
```  1 ``` | ``` <$ ``` | ``` <$ ``` <br>
```  2 ``` | ``` <$ ``` | ``` <$ ``` <br>
```  3 ``` | ``` Nested ``` | ``` Вложенный ```<br>
```  4 ``` | ``` comment ``` | ``` комментарий ```<br>
```  5 ``` | ``` $> ``` | ``` $> ``` <br>
```  6 ``` | ``` <$ ``` | ``` <$ ``` <br>
```  7 ``` | ``` Nested ``` | ``` Вложенный ``` <br>
```  8 ``` | ``` comment ``` | ``` комментарий ``` <br>
```  9 ``` | ``` $> ``` | ``` $> ```<br>
``` 10 ``` | ``` $> ``` | ``` $> ```<br>

Допустимо использование и С/С++ синтаксиса (по этой причине изначально и был добавлен), но в дальнейшем может быть вырезан.<br>
<br>
Теперь мы плавно подошли к рекурсивным вызовам функций.<br>

< файл: ```0.cdlr``` (исходный код на языке ```C$```)>
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

< файл: ```0.cdlr``` (исходный код на языке ```C$```)>
<br>
| код на английском | код на русском |
|-|-|
| ```1``` ```$ Избавляемся от блочных скобочек``` | ```1``` ```$ Избавляемся от блочных скобочек```
| ```2``` ```declare function ExecuteScript()``` | ```2``` ```объявить функцию ВыполнитьСкрипт()```
| ```3``` ```    call function ExecuteScript();``` | ```3``` ```    вызов функции ВыполнитьСкрипт();```

<br>

< ``` Указатель на функцию ```>
<br>
| код на английском | код на русском |
|-|-|
| ```1``` ```int addr = &ExecuteScript();``` | ```1``` ```цел адрес = &ВыполнитьСкрипт();```
| ```2``` ```int addr = ^ExecuteScript();``` | ```2``` ```цел адрес = ^ВыполнитьСкрипт();```
| ```3``` ```int addr = *ExecuteScript();``` | ```3``` ```цел адрес = *ВыполнитьСкрипт();```

Таким образом мы можем получить адрес функции (значение), сохранив его в целочисленную переменную.<br>

< ```Безусловный переход в пределах одной конструкции (аналог switch/case)```>
<br>
| код на английском | код на русском |
|-|-|
| ```   1``` ```byte n = 2;``` | ```   1``` ```байт знач = 2;```
| ```   2``` ```goto (n)``` | ```   2``` ```прыгнуть (знач)```
| ```   3``` ```label 1:``` | ```   3``` ```метка 1:```
| ```   4``` ```label 2:``` | ```   4``` ```метка 2:```
| ```1002``` ```label 1000:``` | ```1002``` ```метка 1000:```

| ```1003``` ```label ?:```|| ```1003``` ```метка ?:```
|-|-|-|

Применяется в тех случаях, когда сразу известно значение, к которому необходимо перейти. Это позволяет избавится от лишних последовательных проверок (работы CPU в холостую), тем самым - повысив производительность (при условии, что вы их используйте в очень большом количестве). Метки всегда должны быть уникальными (без дублирования). Если не будет соответствующего значения, он перейдёт на выполнение кода, идущее после 1002-й строчки кода (об этом позаботится компилятор, и автоматически подставит дополнительную метку, на случай невалидных значений).<br>
<br>

< ```Возврат значени-я(ий) счётчика из цикла```, файл: ```0.cdlr```>
<br>

| № | C$ | C/C++
|-|-|-|
| ``` 1 ``` | ``` int j; ``` | ``` int j; ```
| ``` 2 ``` | ``` for (int i = 1; i != 1000; i ++) {}, j = i; ``` | ``` for (int i = 1; i != 1000; i ++) { if (i == 1000) j = i; } ```
| ``` 3 ``` | ``` for (int i = j; i != 1; i --) {}, j = i; ``` | ``` for (int i = j; i != 1; i --) { if (i == 1) j = i; } ```

В некоторых случаях может пригодиться вытащить значение счётчика из цикла находящегося в локальной области видимости. Посмотрите, как это удобно. Да и к тому лишний раз обходимся без доп. проверки на каждой итерации цикла. В следствии чего, прирост производительности.<br>
<br>

#
```[!] БЛИЖАЙШИЕ НОВОВВЕДЕНИЯ И ОБНОВЛЕНИЯ```<br>
<br>
``` < Создание, переименование и удаление локальных переменных с временем жизни > ``` <br>
``` < Область видимости переменных | инструкция `.{}`> ``` <br>
``` < Динамически выделяемая память на этапе компиляции (не путать с временем выполнения) > ``` <br>
``` < Строковые/текстовые регистры виртуальной машины для работы с динамически выделяемой памятью (организация менеджера памяти) > ``` <br>
``` < Использование унарного апострофа или пробела, для лучшей читабельности больших чисел > ``` <br>
``` < Ветвличный цикл (for/then if/then)> ``` <br>
#


---------------------
* Продолжение следует
---------------------
