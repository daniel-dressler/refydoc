#include "template_tools.h"
#include <string>

namespace refydoc {
namespace html {
	std::string link_base()
	{
		return "./";
	}

	void md()
	{
	}

	void page()
	{
		OUT("<html><head>\n"
			"<link href='%s' rel='stylesheet'>\n"
			"<link href='%s' rel='stylesheet'>\n"
			"<link href='%s' rel='stylesheet'>\n"
			"</head>\n"
			"<body>\n",
			(link_base() + "/bootstrap.css").c_str(),
			(link_base() + "/bootstrap-theme.css").c_str(),
			(link_base() + "/custom.css").c_str()
			);

		DIV("container");
		{
			DIV("container");
			{
				DIV("header");
				{
					UL("nav nav-pills pull-right");
					{
						LI("Documentation", NULL);
						LI("Source", "github.com");
						LI("Download", "github.com/download.zip");
					}
					UL_CLOSE();
					OUT("<h3 class='text-muted'>");
					IMG("elib_greylabel.png", "refydoc_logo");
					OUT("</h3>");
				}
				DIV_CLOSE();
			}
			DIV_CLOSE();

			OUT("<ol class='breadcrumb'>\n");
			{
				LI("C", "#");
				LI("Thread support library", "#");
				LI("Threads", "#");
				LI("thread_create", NULL);
			}
			OUT("</ol>");

			DIV("row");
			{
				DIV("col-lg-12");
				{
					// Generate the html from the markdown
				}
				DIV_CLOSE();
			}
			DIV_CLOSE();

			HR();
			DIV("row");
			{
				DIV("row");
				{
					DIV("col-sm-6 refydoc_deemf");
					{
						H4("Also see in Threads");
						P(); A("third_detach", "#"); OUT(" - a type iding a thread"); P_CLOSE();
					}
					DIV_CLOSE();

					DIV("col-sm-6 refydoc_deemf");
					{
						H4("Related to Theads");
						P(); A("Mutual exclusion", "#"); P_CLOSE();
					}
					DIV_CLOSE();
				}
				DIV_CLOSE();
			}
			DIV_CLOSE();

			HR();
			DIV("col-sm-12");
			{
				IMG("elib_greylabel.png", "refydoc_fullwidth");
				HR();
				OUT("<p style='opacity: 0.5;'> eblib uses");
				A("Refydoc", "refydoc.org");
				OUT(" to assist with documentation</p>");
			}
			DIV_CLOSE();
		}
		DIV_CLOSE();

		OUT("</body></html>\n");
	}

	void generate()
	{
		//foreach page
		page();

	}
}
}

