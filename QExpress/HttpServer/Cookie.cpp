#include "Cookie.h"

using namespace QExpress;

Cookie::Cookie()
{
    version=1;
    maxAge=0;
    secure=false;
}

Cookie::Cookie(const Buffer name, const Buffer value, const int maxAge, const Buffer path, const Buffer comment, const Buffer domain, const bool secure, const bool httpOnly)
{
    this->name=name;
    this->value=value;
    this->maxAge=maxAge;
    this->path=path;
    this->comment=comment;
    this->domain=domain;
    this->secure=secure;
    this->httpOnly=httpOnly;
    this->version=1;
}

Cookie::Cookie(const Buffer source)
{
    version=1;
    maxAge=0;
    secure=false;
    QList<Buffer> list=splitCSV(source);
    foreach(Buffer part, list)
    {

        // Split the part into name and value
        Buffer name;
        Buffer value;
        int posi=part.indexOf('=');
        if (posi)
        {
            name=part.left(posi).trimmed();
            value=part.mid(posi+1).trimmed();
        }
        else
        {
            name=part.trimmed();
            value="";
        }

        // Set fields
        if (name=="Comment")
        {
            comment=value;
        }
        else if (name=="Domain")
        {
            domain=value;
        }
        else if (name=="Max-Age")
        {
            maxAge=value.toInt();
        }
        else if (name=="Path")
        {
            path=value;
        }
        else if (name=="Secure")
        {
            secure=true;
        }
        else if (name=="HttpOnly")
        {
            httpOnly=true;
        }
        else if (name=="Version")
        {
            version=value.toInt();
        }
        else {
            if (this->name.isEmpty())
            {
                this->name=name;
                this->value=value;
            }
            else
            {
                qWarning("Cookie: Ignoring unknown %s=%s",name.data(),value.data());
            }
        }
    }
}

Buffer Cookie::toByteArray() const
{
    Buffer buffer(name);
    buffer.append('=');
    buffer.append(value);
    if (!comment.isEmpty())
    {
        buffer.append("; Comment=");
        buffer.append(comment);
    }
    if (!domain.isEmpty())
    {
        buffer.append("; Domain=");
        buffer.append(domain);
    }
    if (maxAge!=0)
    {
        buffer.append("; Max-Age=");
        buffer.append(Buffer::number(maxAge));
    }
    if (!path.isEmpty())
    {
        buffer.append("; Path=");
        buffer.append(path);
    }
    if (secure) {
        buffer.append("; Secure");
    }
    if (httpOnly) {
        buffer.append("; HttpOnly");
    }
    buffer.append("; Version=");
    buffer.append(Buffer::number(version));
    return buffer;
}

void Cookie::setName(const Buffer name)
{
    this->name=name;
}

void Cookie::setValue(const Buffer value)
{
    this->value=value;
}

void Cookie::setComment(const Buffer comment)
{
    this->comment=comment;
}

void Cookie::setDomain(const Buffer domain)
{
    this->domain=domain;
}

void Cookie::setMaxAge(const int maxAge)
{
    this->maxAge=maxAge;
}

void Cookie::setPath(const Buffer path)
{
    this->path=path;
}

void Cookie::setSecure(const bool secure)
{
    this->secure=secure;
}

void Cookie::setHttpOnly(const bool httpOnly)
{
    this->httpOnly=httpOnly;
}

Buffer Cookie::getName() const
{
    return name;
}

Buffer Cookie::getValue() const
{
    return value;
}

Buffer Cookie::getComment() const
{
    return comment;
}

Buffer Cookie::getDomain() const
{
    return domain;
}

int Cookie::getMaxAge() const
{
    return maxAge;
}

Buffer Cookie::getPath() const
{
    return path;
}

bool Cookie::getSecure() const
{
    return secure;
}

bool Cookie::getHttpOnly() const
{
    return httpOnly;
}

int Cookie::getVersion() const
{
    return version;
}

QList<Buffer> Cookie::splitCSV(const Buffer source)
{
    bool inString=false;
    QList<Buffer> list;
    Buffer buffer;
    for (int i=0; i<source.size(); ++i)
    {
        char c=source.at(i);
        if (inString==false)
        {
            if (c=='\"')
            {
                inString=true;
            }
            else if (c==';')
            {
                Buffer trimmed=buffer.trimmed();
                if (!trimmed.isEmpty())
                {
                    list.append(trimmed);
                }
                buffer.clear();
            }
            else
            {
                buffer.append(c);
            }
        }
        else
        {
            if (c=='\"')
            {
                inString=false;
            }
            else {
                buffer.append(c);
            }
        }
    }
    Buffer trimmed=buffer.trimmed();
    if (!trimmed.isEmpty())
    {
        list.append(trimmed);
    }
    return list;
}
