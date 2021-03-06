// 
// Copyright (C) 2019 Julian Schnabel
// julian-schnabel@posteo.de www.github.com/SchnJulian
// 
// This file is part of AutoHeader.
// 
// AutoHeader must not be copied and/or distributed without the express
// permission of Julian Schnabel.
// 
// 27.10.2019


#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <QString>

static const QString SEELICENSE = R"(
See the file \"LICENSE\" for the full license governing this code. )";
static const QString STANDARD_HEADER = R"(
Copyright (C) <year> <name>
<email> <github>

This file is part of PROJECT.

PROJECT must not be copied and/or distributed without the express
permission of <name>
)";

static const QString STANDART_HEADER_ALT = R"(
This file blongs to {project}.
Copyright (C) <year> <name> <email>
)";

#endif  // TEMPLATES_H
