# 22 april 2015

CXXFILES += \
	windows/alloc.cpp \
	windows/area.cpp \
	windows/areadraw.cpp \
	windows/areaevents.cpp \
	windows/areascroll.cpp \
	windows/areautil.cpp \
	windows/box.cpp \
	windows/button.cpp \
	windows/checkbox.cpp \
	windows/colorbutton.cpp \
	windows/colordialog.cpp \
	windows/combobox.cpp \
	windows/container.cpp \
	windows/control.cpp \
	windows/d2dscratch.cpp \
	windows/datetimepicker.cpp \
	windows/debug.cpp \
	windows/draw.cpp \
	windows/drawmatrix.cpp \
	windows/drawpath.cpp \
	windows/drawtext.cpp \
	windows/dwrite.cpp \
	windows/editablecombo.cpp \
	windows/entry.cpp \
	windows/events.cpp \
	windows/fontbutton.cpp \
	windows/fontdialog.cpp \
	windows/graphemes.cpp \
	windows/group.cpp \
	windows/init.cpp \
	windows/label.cpp \
	windows/main.cpp \
	windows/menu.cpp \
	windows/multilineentry.cpp \
	windows/parent.cpp \
	windows/progressbar.cpp \
	windows/radiobuttons.cpp \
	windows/separator.cpp \
	windows/sizing.cpp \
	windows/slider.cpp \
	windows/spinbox.cpp \
	windows/stddialogs.cpp \
	windows/tab.cpp \
	windows/tabpage.cpp \
	windows/text.cpp \
	windows/utf16.cpp \
	windows/utilwin.cpp \
	windows/window.cpp \
	windows/winpublic.cpp \
	windows/winutil.cpp

HFILES += \
	windows/_uipriv_migrate.hpp \
	windows/area.hpp \
	windows/compilerver.hpp \
	windows/draw.hpp \
	windows/resources.hpp \
	windows/uipriv_windows.hpp \
	windows/winapi.hpp

RCFILES += \
	windows/resources.rc

# LONGTERM split into a separate file or put in GNUmakefile.libui somehow?

# flags for the Windows API
LDFLAGS += $(NATIVE_UI_LDFLAGS)

# flags for building a shared library
ifeq (,$(STATIC))
LDFLAGS += \
	-dll
endif

# TODO flags for warning on undefined symbols

# no need for a soname

# TODO .def file

ifneq (,$(STATIC))
CFLAGS += -D_UI_STATIC
CXXFLAGS += -D_UI_STATIC
RCFLAGS += -D _UI_STATIC
endif
