/* The MIT License
 *
 * Copyright (c) 2020 Piotr Duba
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef INC_LCD_CHARS_H_
#define INC_LCD_CHARS_H_

#define CG_FIRST_CHAR	0x40

uint8_t user_chars[8][8] = {
		{0x00, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x02},	//a ogonek
		{0x02, 0x04, 0x0E, 0x10, 0x10, 0x11, 0x0E, 0x00},	//c ogonek
		{0x00, 0x00, 0x0E, 0x11, 0x1F, 0x10, 0x0E, 0x02},	//e ogonek
		{0x0C, 0x04, 0x06, 0x0C, 0x04, 0x04, 0x0E, 0x00},	//l kreska
		{0x02, 0x04, 0x16, 0x19, 0x11, 0x11, 0x11, 0x00},	//n ogonek
		{0x02, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00},	//o ogonek
		{0x02, 0x04, 0x0E, 0x10, 0x0E, 0x01, 0x1E, 0x00},	//s ogonek
		{0x02, 0x04, 0x1F, 0x02, 0x04, 0x08, 0x1F, 0x00}	//z ogonek
};

#endif /* INC_LCD_CHARS_H_ */
