
# ft_printf
*This project was created as part of the 42 curriculum by `<katakaha>`.*

<details>
<summary>🌐 English README</summary>

## Description

ft_printf prints a string according to a format and returns the number of bytes printed.
If the `write()` function returns an error at any point, the function must return -1
and stop printing immediately.
This implementation receives a format string and replaces certain specifiers with values
stored in a `va_list`, in the exact order they are provided.

For the mandatory part, the following nine specifiers are supported:

c s p d i u x X %


Each specifier must be preceded by `%`.
If the specifier is valid, it is replaced by the corresponding argument from the `va_list`.
If the specifier is not valid, the character is printed as is.
Printing continues until the end of the format string is reached or a `write()` error occurs.

## Instructions

Run the `Makefile` to archive the required files, then compile the library with a test file of your own.

A simple test file is included for convenience. Try it — you just might like it 😉
Here is a sample:

```C
#include <stdio.h>
#include "incs/ft_printf.h"

int main(void)
{
	int c = 3249857;
	char *s = "Random TEST\n";
	void *p = NULL;
	int d = 3249857;
	int i = 3249857;
	unsigned int u = 3249857;
	unsigned int x = 3249857;
	unsigned int X = 3249857;

	printf("-----------------------------------------\n");
	printf("CharsPrinted: %d\n-----------------------------------------\n",
		printf("|Hi! This is a printing test. Good luck!\n"
		       "%15s --> %c\n"
		       "%15s --> %s\n"
		       "%15s --> %p\n"
		       "%15s --> %d\n"
		       "%15s --> %i\n"
		       "%15s --> %u\n"
		       "%15s --> %x\n"
		       "%15s --> %X\n"
		       "%\n%%\n%|\n",
		       "Char", c,
		       "String", s,
		       "Pointer Address", p,
		       "Decimal", d,
		       "Int", i,
		       "Unsigned Dec", u,
		       "Hex Low", x,
		       "Hex Upper", X) - 2);

	printf("CharsPrinted: %d\n-----------------------------------------\n",
		ft_printf("|Hi! This is a printing test. Good luck!\n"
		          "           Char --> %c\n"
		          "         String --> %s\n"
		          "Pointer Address --> %p\n"
		          "        Decimal --> %d\n"
		          "            Int --> %i\n"
		          "   Unsigned Dec --> %u\n"
		          "        Hex Low --> %x\n"
		          "      Hex Upper --> %X\n"
		          "%\n%%\n%|\n",
		          c, s, p, d, i, u, x, X) - 2);

	return (0);
}
```

## Resources

My peer, `<yuonishi>`, introduced me to this method of using function pointers to dispatch behavior.
It matched very well with how I wanted to structure this project, and I was excited to try it.
I think it turned out beautifully.

#### Other resources include:

- Testing against the original `printf()`

- [Reading the official manual:](https://linuxjm.sourceforge.io/html/LDP_man-pages/man3/printf.3.html)

#### Using AI to better understand:

- how integers work under the hood

- naming conventions

- designing control flow so debugging becomes easier

## Reasoning

I chose this style of implementation using function pointers because the logic stays clean and direct.
Using the specifier character as an index to look up the corresponding function is intuitive and easy to read.
Readable code is the primary goal. Clear control flow makes debugging easier,
and function dispatch via lookup avoids long conditional chains while keeping the intent obvious.

#### Design Overview

The core idea of this implementation is to separate parsing, dispatch, and printing.
`ft_printf` walks the format string one character at a time.
A single flag tracks whether the current character is a literal or a format specifier.
When a `%` is encountered, the next character is treated as a potential specifier:
If it is valid, execution is dispatched through a function pointer lookup table.
If it is not valid, the character is printed literally, preceded by `%`.

Specifier handling is done through a static lookup table indexed by the specifier’s ASCII value.
This avoids large conditional chains and keeps the mapping between specifiers and behavior explicit.

All output paths go through `write()`, and every write is checked.
If any write fails, printing stops immediately and -1 is returned.

</details>


&nbsp;
&nbsp;
---
&nbsp;
&nbsp;


<details>
<summary>🇯🇵 日本語版　README</summary>

## 概要

ft_printf は、フォーマット文字列に従って文字列を出力し、出力されたバイト数を返します。  
`write()` 関数が途中でエラーを返した場合、関数は **-1 を返し、即座に出力を停止** します。

この実装ではフォーマット文字列を受け取り、特定の書式指定子を `va_list` に格納された値で、**指定された順序通りに** 置き換えていきます。

必須パートでは、以下の 9 種類の指定子をサポートしています。

c s p d i u x X %

各指定子は `%` によって前置されている必要があります。  
指定子が有効な場合は、`va_list` から対応する引数に置き換えられます。  
無効な指定子の場合は、その文字がそのまま出力されます。

フォーマット文字列の終端に到達するか、`write()` エラーが発生するまで処理は続行されます。

## 使用方法

`Makefile` を実行して必要なファイルをアーカイブし、その後ライブラリを任意のテストファイルと一緒にコンパイルしてください。

動作確認用に、簡単なテストファイルも用意しています。ぜひ試してみてください 😉  
以下はサンプルです：

```C
#include <stdio.h>
#include "incs/ft_printf.h"

int main(void)
{
	int c = 3249857;
	char *s = "Random TEST\n";
	void *p = NULL;
	int d = 3249857;
	int i = 3249857;
	unsigned int u = 3249857;
	unsigned int x = 3249857;
	unsigned int X = 3249857;

	printf("-----------------------------------------\n");
	printf("CharsPrinted: %d\n-----------------------------------------\n",
		printf("|Hi! This is a printing test. Good luck!\n"
		       "%15s --> %c\n"
		       "%15s --> %s\n"
		       "%15s --> %p\n"
		       "%15s --> %d\n"
		       "%15s --> %i\n"
		       "%15s --> %u\n"
		       "%15s --> %x\n"
		       "%15s --> %X\n"
		       "%\n%%\n%|\n",
		       "Char", c,
		       "String", s,
		       "Pointer Address", p,
		       "Decimal", d,
		       "Int", i,
		       "Unsigned Dec", u,
		       "Hex Low", x,
		       "Hex Upper", X) - 2);

	printf("CharsPrinted: %d\n-----------------------------------------\n",
		ft_printf("|Hi! This is a printing test. Good luck!\n"
		          "           Char --> %c\n"
		          "         String --> %s\n"
		          "Pointer Address --> %p\n"
		          "        Decimal --> %d\n"
		          "            Int --> %i\n"
		          "   Unsigned Dec --> %u\n"
		          "        Hex Low --> %x\n"
		          "      Hex Upper --> %X\n"
		          "%\n%%\n%|\n",
		          c, s, p, d, i, u, x, X) - 2);

	return (0);
}
```

## 参考資料
この実装で用いている 関数ポインタによるディスパッチ手法 は、同じピアの `<yuonishi>` に紹介してもらいました。
自分が考えていた構造と非常に相性が良く、ぜひ試してみたいと思いました。
結果として、とても美しい形にまとまったと感じています。

#### その他の参考資料：
- オリジナルの `printf()` との動作比較テスト

- [公式マニュアルの参照：](https://linuxjm.sourceforge.io/html/LDP_man-pages/man3/printf.3.html)

#### AI を使って理解を深めた内容：
- 整数が内部的にどのように扱われているか

- 命名規則

- デバッグしやすい制御フローの設計方法

## 設計の意図
この実装で関数ポインタを用いた理由は、ロジックを シンプルかつ直接的 に保つためです。
指定子の文字をインデックスとして対応する関数を参照する方法は直感的で、読みやすいと考えています。

可読性を最優先にしており、明確な制御フローはデバッグのしやすさにも直結します。
関数ポインタによるディスパッチを使うことで、長い条件分岐を避けつつ、処理の意図を明確に保つことができます。

#### 設計概要
この実装の中核となる考え方は、パース・ディスパッチ・出力 を明確に分離することです。

`ft_printf` はフォーマット文字列を 1 文字ずつ読み進めます。
現在の文字がリテラルか書式指定子かを判定するために、単一のフラグを使用しています。

`%` が現れた場合、次の文字は書式指定子候補として扱われます。
有効な指定子であれば、関数ポインタのルックアップテーブルを通じて対応する処理にディスパッチされます。
無効な指定子の場合は、`%` に続けてその文字をそのまま出力します。

指定子の処理は、ASCII 値をインデックスとした静的なルックアップテーブルによって管理されています。
これにより、大きな条件分岐を避けつつ、指定子と処理の対応関係を明示的に保っています。

すべての出力は `write()` を通じて行われ、各書き込みは必ずチェックされます。
いずれかの `write()` が失敗した場合、処理は即座に中断され、-1 が返されます。
</details>
