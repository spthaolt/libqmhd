#include "qmhdglobal.h"

static const char* s_method_strings[] = {
#define XX(name, string) #string,
    QMHD_METHOD_MAP(XX)
#undef XX
    0
};

QMHDMethod qmhd_method_from_string(const char* method)
{
    for (int i = 0; s_method_strings[i] != 0; ++i) {
        if (qstricmp(s_method_strings[i], method) == 0)
            return (QMHDMethod) i;
    }
    return QMHDMethod::Unknown;
}

QMHDHttpVersion qmhd_http_version_from_string(const char* http_version)
{
    if (qstrcmp("HTTP/1.0", http_version) == 0)
        return QMHDHttpVersion::Http_1_0;
    if (qstrcmp("HTTP/1.1", http_version) == 0)
        return QMHDHttpVersion::Http_1_1;
    return QMHDHttpVersion::Unknown;
}