Инструкция по применению компилятора и виртуальной машины C$ (Си-доллар).
-
Язык программирования С$ был придуман в целях написания сценариев (в основном под игры), в которых требуется коллосальное количество создания переменных и управления ими.

Для C$ используется расширение (формат) файл|а(ов), как: – `.cdlr`.<br><br>
Точка выполнения скрипта начинается с создания основной функции. Есть два стандартных подхода к этому: <br>

1: придумываем любое название для функции (обычно не применяется на практике);<br>
2: название для функции соответствует имени файла (часто применимо на практике);<br>
<br>
В обоих случаях расположение функции должно быть в самом начале скрипта. <br><br>

``` 1 ``` | ``` ExecuteScript(){} ``` или ``` ВыполнитьСкрипт(){} ``` <br>
или <br>
``` 1 ``` | ``` ScriptEntryPoint(){} ``` или  ``` точкаВходаВскрипт(){} ``` <br>
или <br>
``` 1 ``` | ``` Script(){} ``` или ``` Скрипт(){} ``` <br><br>

Исходя из того, что функции выполняют какие-либо действия, то и названия у них должны быть соответствующие. На мой взгляд, первый вариант можно считать самым подходящим.

<br>
<br>

---------------------
* Продолжение следует
---------------------
