/* 
Copyright (C) 2019 Julian Schnabel - julian schnabel@outlook.com

This file is part of AutoHeader. (https://github.com/SchnJulian/AutoHeader)

AutoHeader is licensed under GPL v. 3. See LICENSE for further information. */

#include "header.h"
Header::Header() = default;
Header::~Header() = default;
QString Header::getContent() const { return content; }
void Header::setContent(const QString& value) { content = value; }
