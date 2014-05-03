#include "template_tools.h"
namespace refydoc {
namespace html {
	void generate()
	{
		OUT("<html><head>\n"
			"<link href='%s' rel='stylesheet'>\n"
			"<link href='%s' rel='stylesheet'>\n"
			"<link href='%s' rel='stylesheet'>\n"
			"</head>\n"
			"<body>\n");

		OUT("</body></html>\n");
	}
}
}

