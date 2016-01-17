#include <stdlib.h>
#include <assert.h>

#include <traildb.h>

int main(int argc, char** argv)
{
    const char *fields[] = {};
    tdb_cons* c = tdb_cons_init();
    assert(tdb_cons_open(c, argv[1], fields, 0) == 0);
    assert(tdb_cons_finalize(c) == 0);
    tdb_cons_close(c);

    tdb* t = tdb_init();
    assert(tdb_open(t, argv[1]) == 0);
    assert(tdb_version(t) == TDB_VERSION_LATEST);
    tdb_close(t);

    return 0;
}