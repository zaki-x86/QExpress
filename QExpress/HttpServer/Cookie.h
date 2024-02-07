#ifndef QEXPRESS_COOKIE_H_
#define QEXPRESS_COOKIE_H_

#include <QList>

#include "Globals.h"

namespace QExpress {

/**
  HTTP cookie as defined in RFC 2109. This class can also parse
  RFC 2965 cookies, but skips fields that are not defined in RFC
  2109.
*/

    class Cookie
    {
    public:

        /** Creates an empty cookie */
        Cookie();

        /**
         Create a cookie and set name/value pair.
        @param name name of the cookie
        @param value value of the cookie
        @param maxAge maximum age of the cookie in seconds. 0=discard immediately
        @param path Path for that the cookie will be sent, default="/" which means the whole domain
        @param comment Optional comment, may be displayed by the web browser somewhere
        @param domain Optional domain for that the cookie will be sent. Defaults to the current domain
        @param secure If true, the cookie will be sent by the browser to the server only on secure connections
        @param httpOnly If true, the browser does not allow client-side scripts to access the cookie
        */
        Cookie(const Buffer name, const Buffer value, const int maxAge,
                const Buffer path="/", const Buffer comment=Buffer(),
                const Buffer domain=Buffer(), const bool secure=false,
                const bool httpOnly=false);

        /**
         Create a cookie from a string.
        @param source String as received in a HTTP Cookie2 header.
        */
        Cookie(const Buffer source);

        /** Convert this cookie to a string that may be used in a Set-Cookie header. */
        Buffer toByteArray() const ;

        /**
         Split a string list into parts, where each part is delimited by semicolon.
        Semicolons within double quotes are skipped. Double quotes are removed.
        */
        static QList<Buffer> splitCSV(const Buffer source);

        /** Set the name of this cookie */
        void setName(const Buffer name);

        /** Set the value of this cookie */
        void setValue(const Buffer value);

        /** Set the comment of this cookie */
        void setComment(const Buffer comment);

        /** Set the domain of this cookie */
        void setDomain(const Buffer domain);

        /** Set the maximum age of this cookie in seconds. 0=discard immediately */
        void setMaxAge(const int maxAge);

        /** Set the path for that the cookie will be sent, default="/" which means the whole domain */
        void setPath(const Buffer path);

        /** Set secure mode, so that the cookie will be sent by the browser to the server only on secure connections */
        void setSecure(const bool secure);

        /** Set HTTP-only mode, so that he browser does not allow client-side scripts to access the cookie */
        void setHttpOnly(const bool httpOnly);

        /** Get the name of this cookie */
        Buffer getName() const;

        /** Get the value of this cookie */
        Buffer getValue() const;

        /** Get the comment of this cookie */
        Buffer getComment() const;

        /** Get the domain of this cookie */
        Buffer getDomain() const;

        /** Get the maximum age of this cookie in seconds. */
        int getMaxAge() const;

        /** Set the path of this cookie */
        Buffer getPath() const;

        /** Get the secure flag of this cookie */
        bool getSecure() const;

        /** Get the HTTP-only flag of this cookie */
        bool getHttpOnly() const;

        /** Returns always 1 */
        int getVersion() const;

    private:

        Buffer name;
        Buffer value;
        Buffer comment;
        Buffer domain;
        int maxAge;
        Buffer path;
        bool secure;
        bool httpOnly;
        int version;
    };

}

#endif // !QEXPRESS_COOKIE_H_
