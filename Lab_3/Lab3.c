/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

void lexicographic(const char* str, size_t len) {
    char* s = (char*)malloc( len);
    strcpy( s, str);
	for(int i = len - 2; i > 0; i--) {
		for( int j = 0; j < i; j++) {
			if(s[j] > s[j + 1]) {
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
	printf("Упорядочить  текст  лексикографически,  в  порядке  возрастания  ASCII-кода:\n");
	printf("%s -> ", str);
	printf("%s", s);
}


void r_after_space( const char* str, size_t len) {
    int cnt = 0;
    for(int i = 0; i< len - 1; i++) {
        if(str[i] == 0x72) {
            cnt++;
        }
    }
    
    char* s = (char*) malloc (len + cnt);
    
    for(int i = 0, j = 0; i < len - 1; i++, j++) {
       s[j] = str[i];
       if(str[i] == 0x72) {
           s[j + 1] = 0x20;
           j++;
       }
    }
    printf("Вставить пробелы после символа “r”:\n");
    printf("%s -> ", str);
    printf("%s", s);
}

void change_x_on_X(char x, const char* str, size_t len) {
    char* s = (char*)malloc( len);
    strcpy( s, str);
    for(int i = 0; i < len - 2; i++) {
        if(s[i] == x) {
					s[i] = s[i] - 0x20;
				}
    }
    printf("Заменить прописную букву “x” на заглавную в тексте:\n");
    printf("%s -> ", str);
	printf("%s", s);
}

void binary_to_hex(const char* s_bin, size_t len) {
	int binary = 0;
	int hexadecimal = 0;
	int remainder = 0;
	int k = 1;
	int length;
	
	if((len - 1) % 4 > 0) {
		length = ((len - 1) / 4) + 1;
	} else {
		length = (len - 1) / 4;
	}
	
	for(int i = 0; i < len - 1; i++) {
		binary *= 10;
		binary += (s_bin[i] - 0x30);
	}
	while(binary != 0) {
		remainder = binary % 10;
		hexadecimal = hexadecimal + remainder * k;
		k *= 2;
		binary /= 10;
	}
	
	//char* s_hex = (char*) malloc (length);
	char s_hex[100];
	int i = 0;
	while(hexadecimal != 0) {
		int h_r = hexadecimal % 16;
		if (h_r > 9) {
			s_hex[i] = 0x30 + h_r + 7;
		} else {
			s_hex[i] = 0x30 + h_r;
		}
		hexadecimal /= 16;
		i++;
	}
	
	//printf("%c", *s_hex);
	printf("Символьное (в ASCII) преобразование двоичного числа в шестнадцатеричное:\n");
	printf("%s -> ", s_bin);
	for(i; i >= 0; i--) {
	    printf("%c", s_hex[i]);
	}
}

void hex_to_binary(const char* s_hex) {
    int i = 0;
    printf("Символьное (в ASCII) преобразование шестнадцатеричного числа в двоичное:\n");
    printf("%s -> ", s_hex);
	while (s_hex[i])
    {
        switch (s_hex[i])
        {
        case '0':
            printf("0000"); break;
        case '1':
            printf("0001"); break;
        case '2':
            printf("0010"); break;
        case '3':
            printf("0011"); break;
        case '4':
            printf("0100"); break;
        case '5':
            printf("0101"); break;
        case '6':
            printf("0110"); break;
        case '7':
            printf("0111"); break;
        case '8':
            printf("1000"); break;
        case '9':
            printf("1001"); break;
        case 'A':
            printf("1010"); break;
        case 'B':
            printf("1011"); break;
        case 'C':
            printf("1100"); break;
        case 'D':
            printf("1101"); break;
        case 'E':
            printf("1110"); break;
        case 'F':
            printf("1111"); break;
        case 'a':
            printf("1010"); break;
        case 'b':
            printf("1011"); break;
        case 'c':
            printf("1100"); break;
        case 'd':
            printf("1101"); break;
        case 'e':
            printf("1110"); break;
        case 'f':
            printf("1111"); break;
        default:
            printf("\n Invalid hexa digit %c ", s_hex[i]);
            return;
        }
        i++;
    }
}

void binary_to_decimal(const char* s_bin, size_t len) {
	int binary = 0;
	int decimal = 0;
	int remainder = 0;
	int k = 1;
	
	for(int i = 0; i < len - 1; i++) {
		binary *= 10;
		binary += (s_bin[i] - 0x30);
	}
	while(binary != 0) {
		remainder = binary % 10;
		decimal = decimal + remainder * k;
		k *= 2;
		binary /= 10;
	}
	int cnt = 0;
	int f_decimal = decimal;
	while(f_decimal != 0) {
		f_decimal /= 10;
		cnt++;
	}
	
	char* s_decimal = (char*) malloc (cnt);
	int i = 0;
	while(decimal != 0) {
		int d_r = decimal % 10;
		s_decimal[i] = 0x30 + d_r;
		decimal /= 10;
		i++;
	}
	printf("Символьное двоичное число преобразовать в символьное десятичное:\n");
	printf("%s -> ", s_bin);
	for(i; i >= 0; i--) {
	printf("%c", s_decimal[i]);
	}
}

void decimal_to_hex(const char* s_bin, size_t len) {
	int decimal = 0;
	int remainder = 0;
	int k = 1;
	char hexadecimalnum[100];
	
	for(int i = 0; i < len - 1; i++) {
		decimal *= 10;
		decimal += (s_bin[i] - 0x30);
	}
	
	int j = 0;
	while (decimal != 0)
    {
        remainder = decimal % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        decimal /= 16;
        j++;
    }
	printf("Символьное (в ASCII) преобразование десятичного числа в шестнадцатеричное:\n");	
		printf("%s -> ", s_bin);
		for (int i = j; i >= 0; i--)
            printf("%c", hexadecimalnum[i]);
}

void hex_to_decimal(const char* s_hex, size_t len) {
	long long decimal = 0;;
	len--;
	int val = 0;
	for(int i = 0; i <= len; i++) {
		if(s_hex[i]>='0' && s_hex[i]<='9'){
			val = s_hex[i] - 48;
    } else if(s_hex[i]>='a' && s_hex[i]<='f'){
      val = s_hex[i] - 97 + 10;
    } else if(s_hex[i]>='A' && s_hex[i]<='F'){
      val = s_hex[i] - 65 + 10;
    }
		decimal += val * pow(16, len - 1);
		len--;
	}
	
	char s_decimal[100];
	int i = 0;
	while(decimal != 0) {
		int d_r = decimal % 10;
		s_decimal[i] = 0x30 + d_r;
		decimal /= 10;
		i++;
	}
	printf("Символьное (в ASCII) преобразование шестнадцатеричного числа в десятичное:\n");
	printf("%s -> ", s_hex);
	for(i; i >= 0; i--) {
	printf("%c", s_decimal[i]);
	}
}

void convert_to_log_form_dec(const char* s_dec, size_t len) {
	int sign = 0;
	int coma = 0;
	int decimal = 0;
	for(int i = 0; i < len - 1; i++) {
		if(s_dec[i] == 0x2D) {
			sign = 1;
			continue;
		}
		if(s_dec[i] == 0x2C) {
			coma = i;
			continue;
		}
		decimal *= 10;
	    decimal += (s_dec[i] - 0x30);
	}
	//printf("\n%d %d %d %c\n", sign, coma, decimal, 0x2C);
	
	char s_decimal[100] = {'0','0','0','0','0','0','0'};
	
	if(sign == 1) {
		coma -= 1;
	}
		
	s_decimal[0] = 'e';
	s_decimal[1] = '+';
	if(coma > 9) {
		int r = coma % 10;
		s_decimal[2] = r;
		r = coma / 10;
		s_decimal[3] = r;
	} else {
		s_decimal[3] = coma + 0x30; 
		//printf("\n%d\n", s_decimal[3]);
	}
		s_decimal[4] = 0x20;
		s_decimal[5] = '-';
		s_decimal[6] = '0';
		s_decimal[7] = ',';
		int i = 8;
		while(decimal != 0) {
			int d_r = decimal % 10;
			s_decimal[i] = d_r + 0x30;
			i++;
			decimal /= 10;
		}
		printf("Преобразовать число с естественной запятой в полулогарифмическую форму в десятичной системе с учетом знака мантиссы:\n");
		printf("%s -> ", s_dec);
		for(int j = 0; j < 8; j++) {
		    if(s_decimal[i] == '0') {
		        continue;
		    }
			printf("%c", s_decimal[j]);
		}
		for(int j = i; j >= 8; j--) {
			printf("%c", s_decimal[j]);
		}
}

void add_sub(const char* s_dec, size_t len) {
	int x = 0;
	int y = 0;
	int operation = 1;
	int j;
	for(int i = 0; i < len - 1; i++){
		if(s_dec[i] == '+') {
			operation = 0;
			j = i;
			//printf("x = %d ", x);
			break;
		} else if(s_dec[i] == '-') {
		    j = i;
		    break;
		}
		x *= 10; 
		x += s_dec[i] - 0x30;
	}
 	//printf("x = %d ", x);
	
	for(int i = j + 1; i < len - 1; i++) {
		y *= 10;
		y += s_dec[i] - 0x30;
	}
	
	//printf(" y = %d ", y);
	if(operation == 1) {
	    x = x - y;
	} else {
	    x = x + y;
	}
	j = 0;
	//printf(" x = %d ", x);
	char s_decimal[100];
	while(x != 0) {
		int d_r = x % 10;
		s_decimal[j] = d_r + 0x30;
		x /= 10;
		j++;
	}
	printf("Десятичное сложение (вычитание) в неупакованных форматах, положение запятой фиксировано:\n");
	printf("%s -> ", s_dec);
	for(j; j >= 0; j--) {
		printf("%c", s_decimal[j]);
	}
}

// void to_from_Manchester(const char* s_bin, size_t len) {
// 	const unsigned int Manchester = 43690;
// 	char* double_s_bin = (char*) malloc ((2 * len) - 1);
// 	for(int i, j; i <  (len - 1); i++, j += 2) {
// 		double_s_bin[j] = s_bin[i];
// 		double_s_bin[j + 1] = s_bin[i];
// 	}
// 	printf("Преобразовать символьный двоичный код в символьный Манчестерский код и восстановить исходный двоичный\n");
// 	printf("%s -> ", double_s_bin);
// 	for(int i = 0; i < (len - 1) * 2; i++) {
// 	    printf("%c", double_s_bin[i]);
// 	}
// 	printf(" (+) \n");
// 	printf("1010101010101010 синхросигнал\n");
// 	printf(" -> ");
// 	for(int i = 0; i < (2 * len) - 1; i++) {
// 		binary *= 10;
// 		binary += (s_bin[i] - 0x30);
// 	}
// 	while(binary != 0) {
// 		remainder = binary % 10;
// 		decimal = decimal + remainder * k;
// 		k *= 2;
// 		binary /= 10;
// 	}
//}

void money_change(const char* s_bin, size_t len) {
    printf("Сформировать сдачу минимальным количеством монет достоинством 50, 10, 5, 1 копеек и проверить обратным преобразованием:\n");
    printf("%s -> ", s_bin);
    
	int array[4] = {50, 10, 5, 1};
	int n = 0;
	for(int i = 0; i < len - 1; i++) {
		n *= 10;
		n += (s_bin[i] - 0x30);
	}
	//printf("%d", n);
	int i = 0;
	while (n != 0) {
		while(n >= array[i]) {
			n -= array[i];
			printf("%d ", array[i]);
		}
		i++;
	}
}

void Gronsfeld(const char* s_dec, size_t len) {
    printf("Шифрование и дешифрование Гронсфельда:\n");
    printf("%s -> ", s_dec);
    int key[4] = {2, 0, 1, 5};
    int k_length = sizeof(key) / sizeof(int);
    char shif[len - 1];
    char deshif[len - 1];
    for(int i = 0; i < len - 1; i++) {
        shif[i] = s_dec[i] + key[i % k_length]; 
    }
    
    for(int i = 0; i < len - 1; i++) {
        printf("%c", shif[i]);
    }
    printf("\n");
    
    for(int i = 0; i < len - 1; i++) {
        printf("%c", shif[i]);
    }
    printf(" -> ");
    for(int i = 0; i < len - 1; i++) {
        deshif[i] = shif[i] - key[i % k_length]; 
    }
    
        for(int i = 0; i < len - 1; i++) {
        printf("%c", deshif[i]);
    }
}

void impuls(const char* s_dec, size_t len) {
    printf("Преобразование двоичной импульсной последовательности в 3-значный код, перепад 0/1 обозначается 1, 1/0 обозначается 2, отсутствие перепада – 0:\n");
    printf("%s -> ", s_dec);
    int binary[len - 1];
    for(int i = len - 2, j = 0; i >= 0; i--, j++) {
        binary[j] = s_dec[i] - 0x30;
    }
    int impuls[len - 2];
    for(int i = 0; i < len - 2; i++) {
        if((binary[i] == 1 && binary[i + 1] == 1) || (binary[i] == 0 && binary[i + 1] == 0)) {
            printf("%d ", 0);
            impuls[i] = 0;
        } else if(binary[i] == 1 && binary[i + 1] == 0) {
            printf("%d ", 2);
            impuls[i] = 2;
        } else {
            printf("%d ", 1);
            impuls[i] = 1;
        }
    }
}

void JTAG_scan(const char* s_bin, size_t len, int n) {
    if(n < 3) {
        printf("Wrong, You should enter number > 3");
        return;
    }
    char str[100];
    for(int i = len -2, j = 0; i >= 0; i++, j++) {
        if((n - 3) == j) {
            str[0] = s_bin[i];
            str[1] = s_bin[i - 1];
            str[2] = s_bin[i - 2];
            break;
        }
    }
    printf("Регистр граничного сканирования n-контактов в JTAG-интерфейсе имеет длину 3n бит. Выбрать 3-хбитную i-ую ячейку в регистре. Нумерация битов регистра справа налево 3n,…2,1,0:\n");
    printf("%s -> ", s_bin);
    for(int i = 0; i < 3; i++) {
        printf("%c", str[i]);
    }
}
int main() {
  const char* str = "This programmator";
    
  lexicographic(str, 18);                        
  printf("\n");
  r_after_space(str, 18);                        
  printf("\n");          
  change_x_on_X('a', str, 18);              
  printf("\n");
  binary_to_hex("0001111", 8);                  
  printf("\n");
  hex_to_binary("24e");                 
  printf("\n");
  binary_to_decimal("01110101", 9);         
  printf("\n");
  decimal_to_hex("590", 4);                     
  printf("\n");
  hex_to_decimal("2E", 3);                      
  printf("\n");
  convert_to_log_form_dec("-25,023", 8);         
  printf("\n");
  add_sub("2557-659", 9);                        
  printf("\n");
  money_change("132", 4);
  printf("\n");
  Gronsfeld("GRONSFELD", 10);
  printf("\n");
  impuls("010001011", 10);
  printf("\n");
  JTAG_scan("1011001101011110101", 20, 3);
  printf("\n");
    return 0;
}
