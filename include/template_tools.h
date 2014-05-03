#pragma once

#include <stdio.h>
#define file_handler stdout
#define OUT(...) fprintf(file_handler, __VA_ARGS__)

#define A(title, link) \
	OUT("<a href='%s'>%s</a>", link, title)
#define H1(title) \
	OUT("<h1>%s</h1>\n", title)
#define H2(title) \
	OUT("<h2>%s</h2>\n", title)
#define H4(title) \
	OUT("<h4>%s</h4>\n", title)
#define CODE(code) \
	OUT("<code>%s</code>\n", code)
#define HR() \
	OUT("<hr>\n");

#define P() \
	OUT("<p>\n");
#define P_CLOSE() \
	OUT("</p>\n");

#define DIV(classes) \
	OUT("<div class='"); \
	OUT("%s", classes); \
	OUT("'>\n")
#define DIV_CLOSE() \
	OUT("</div>\n")

#define UL(classes) \
	OUT("<ul class='"); \
	OUT("%s", classes); \
	OUT("'>\n")
#define UL_CLOSE() \
	OUT("</ul>\n")

#define LI(title, link) \
	if (link == NULL) { \
		OUT("<li class='active'>"); \
		OUT("%s", title); \
	} else { \
		OUT("<li>"); \
		A(title, link); \
	} \
	OUT("</li>\n")
