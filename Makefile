#---------------------------------------------------------------------------------
# Options
#---------------------------------------------------------------------------------
CXX     :=  g++
DEFINES :=  -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS  :=  -g -Wall $(DEFINES)
CXXFLAGS:=  $(CFLAGS) -std=c++11 -fPIC

ifneq ($(BUILD),$(notdir $(CURDIR)))
INCPATHS:=  -I. -isystem $(CURDIR)/build/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/ -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/  -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtOpenGL -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtWidgets  -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtGui -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtCore -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/mkspecs/linux-g++-64
else
INCPATHS:=  -I. -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/ -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/  -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtOpenGL -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtWidgets  -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtGui -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/include/QtCore -isystem $(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/mkspecs/linux-g++-64
endif

LDFLAGS :=  -g -Wl,-rpath,$(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/lib
export LD_LIBRARY_PATH=$(CURDIR)/qt_resources/qt-everywhere-opensource-src-5.5.0/qtbase/lib

LIBS    :=  -lQt5Gui -lQt5Widgets -lQt5Core -lQt5OpenGL -lpthread
TARGET  :=  qt_solar_clock
BUILD   :=  build
SOURCES :=  src
INCLUDES:=  src include 


ifneq ($(BUILD),$(notdir $(CURDIR))) #We are not in the build directory
#---------------------------------------------------------------------------------
export OUTPUT   :=  $(CURDIR)/$(TARGET)

export VPATH    :=  $(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
                    $(foreach dir,$(INCLUDES),$(CURDIR)/$(dir)) 

CPPFILES    :=  main.cpp celestialbody.cpp mainwindow.cpp orbitaltrack.cpp solarsystem.cpp
HFILES      :=  celestialbody.h mainwindow.h orbitaltrack.h solarsystem.h ui_mainwindow.h

export LD   :=  $(CXX)

export OFILES   :=  $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(HFILES:.h=.moc.o) 

export INCLUDE  :=  $(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) $(INCPATHS)

#---------------------------------------------------------------------------------
.PHONY: $(BUILD) clean 
#------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET)

#---------------------------------------------------------------------------------
else
all: $(OUTPUT)

#---------------------------------------------------------------------------------
$(OUTPUT): $(OFILES)
	@echo built ... $(notdir $@)
	@$(LD) $(LDFLAGS) $(OFILES) -o $@ $(LIBS)

#---------------------------------------------------------------------------------
%.o: %.c
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(C) $(CFLAGS) $(INCLUDE) -c $< -o $@

#---------------------------------------------------------------------------------
%.o: %.cpp
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(CXX) $(CXXFLAGS) $(INCPATHS) $(INCLUDE) -c $< -o $@

#---------------------------------------------------------------------------------
moc_%.cpp: %.h
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@/usr/local/Qt-5.5.0/bin/moc $(DEFINES) $(HFILES) $<  -o $@

#---------------------------------------------------------------------------------
%.moc.o: moc_%.cpp
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


endif
