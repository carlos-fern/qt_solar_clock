#---------------------------------------------------------------------------------
# Options
#---------------------------------------------------------------------------------
CXX     :=  g++
DEFINES :=  -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS  :=  -g -Wall $(DEFINES)
CXXFLAGS:=  $(CFLAGS) -std=c++11 -fPIC

INCPATHS:=  -I. -isystem /usr/local/Qt-5.5.0/ -isystem /usr/local/Qt-5.5.0/include/  -isystem /usr/local/Qt-5.5.0/include/QtOpenGL -isystem /usr/local/Qt-5.5.0/include/QtWidgets  -isystem /usr/local/Qt-5.5.0/include/QtGui -isystem /usr/local/Qt-5.5.0/include/QtCore -isystem /usr/local/Qt-5.5.0/mkspecs/linux-g++-64
LDFLAGS :=  -g -Wl,-rpath,/usr/local/Qt-5.5.0/lib
export LIBRARY_PATH = /usr/local/Qt-5.5.0/lib
export LD_LIBRARY_PATH=/usr/local/Qt-5.5.0/lib

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
