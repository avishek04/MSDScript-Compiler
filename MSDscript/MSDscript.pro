QT+=widgets

HEADERS += \
    AddExpr.hpp \
    BoolExpr.hpp \
    BoolVal.hpp \
    CallExpr.hpp \
    EmptyEnv.hpp \
    Env.hpp \
    EqExpr.hpp \
    Expr.hpp \
    ExtendedEnv.hpp \
    FunExpr.hpp \
    FunVal.hpp \
    IfExpr.hpp \
    MultExpr.hpp \
    NumExpr.hpp \
    NumVal.hpp \
    Val.hpp \
    VariableExpr.hpp \
    _letExpr.hpp \
    catch.h \
    mainwidget.h \
    parse.hpp \
    pointer.hpp

SOURCES += \
    AddExpr.cpp \
    BoolExpr.cpp \
    BoolVal.cpp \
    CallExpr.cpp \
    EmptyEnv.cpp \
    EqExpr.cpp \
    ExtendedEnv.cpp \
    FunExpr.cpp \
    FunVal.cpp \
    IfExpr.cpp \
    MultExpr.cpp \
    NumExpr.cpp \
    NumVal.cpp \
    VariableExpr.cpp \
    _letExpr.cpp \
    main.cpp \
    mainwidget.cpp \
    parse.cpp

DISTFILES += \
    test.txt
