Инструкция по применению компилятора и виртуальной машины C$ (Си-доллар).
-
Язык программирования С$ был придуман в целях написания сценариев (особенно хорошее применение найдёт в геймдеве).
Можно рассматривать как альтернативу и замену – Pawn (устаревший и малофункциональный) с Lua (не Си-подобный).
В остальном имеется много всяких нужных плюшек, которых нет в том же Pawn/Lua и прочих скриптовых языках.

Для C$ используется расширение (формат) файл|а(ов), как: – `.cdlr`.<br><br>
Точка выполнения скрипта начинается с создания основной функции. Есть два стандартных подхода к этому: <br>

1]: придумываем любое название для функции (обычно не применяется на практике);<br>
2]: название для функции соответствует имени файла (часто применимо на практике);<br>
<br>
В обоих случаях расположение функции должно быть в самом начале скрипта. <br><br>
Файл ``` ExecuteScript.dlr ``` или ``` ВыполнитьСкрипт.dlr ``` <br>

| Линия | Исходный код |
|------|-
| 1 | ExecuteScript(){} или ВыполнитьСкрипт(){}

``` 1 ``` | ``` ExecuteScript(){} ``` или ``` ВыполнитьСкрипт(){} ```
-
или

``` 1 ``` | ``` ScriptEntryPoint(){} ``` или  ``` точкаВходаВскрипт(){} ```
-
или

``` 1 ``` | ``` Script(){} ``` или ``` Скрипт(){} ```
-
или

``` 1 ``` | ``` unnamed(){} ``` или ``` безымянная(){} ```
-
Исходя из того, что функции выполняют какие-либо действия, то и названия у них должны быть соответствующие. На мой взгляд, первый вариант можно считать самым подходящим.

<br>

---------------------
* Продолжение следует
---------------------
