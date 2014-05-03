Refydoc
=======

Refydoc is a purpose built static site generator for reference-grade
documentation. Refydoc exists to bring [cppreference](cppreference.com) quality
documentation to small and medium software projects.

Writing quality documentation is hard and cannot be automated. Instead Refydoc
assists by automating the brain-dead drudge work. This frees time for writing
real explainations and real examples, things your users will appreciate.

Features
--------

* Refydoc consumes unadulterated markdown. There are no new syntax elements added.
Instead Refydoc overloads existing markdown syntax to denote linked references.
The net result being the markdown markedup documentation you write targeting
Refydoc also serves as textual documentation.

* Documentation sites generated from Refydoc use only relative links. This means
you can move the documentation around a file system without breaking links.

* Refydoc is written in C++14 and is fast.

Usage
-----
Refydoc requires either Clang or GCC 4.7+

Compile:
	git clone https://github.com/daniel-dressler/refydoc.git;
	cd refydoc;
	git submodule init && git submodule update;
	make redep && make

Use Refydoc to generate documentation:
	mkdir -p doc_site;
	cd doc_site;
	../bin/refydoc ../doc/refydoc/refydoc.ini

The single argument to refydoc should a path to the settings for your
documentation.
	







