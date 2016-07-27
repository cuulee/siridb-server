/*
 * pools.h - Generate pools lookup.
 *
 * author       : Jeroen van der Heijden
 * email        : jeroen@transceptor.technology
 * copyright    : 2016, Transceptor Technology
 *
 * changes
 *  - initial version, 25-03-2016
 *
 */
#pragma once

#include <siri/db/db.h>
#include <inttypes.h>
#include <siri/db/pool.h>
#include <siri/net/promise.h>
#include <slist/slist.h>
#include <siri/net/pkg.h>

typedef struct siridb_s siridb_t;
typedef struct siridb_pool_s siridb_pool_t;

#define SIRIDB_LOOKUP_SZ 8192

typedef uint_fast16_t siridb_lookup_t[SIRIDB_LOOKUP_SZ];
typedef void (* sirinet_promises_cb)(
        slist_t * promises,
        void * data);

typedef struct siridb_pools_s
{
    uint16_t len;
    siridb_pool_t * pool;
    siridb_lookup_t * lookup;
    siridb_lookup_t * prev_lookup;
} siridb_pools_t;

void siridb_pools_init(siridb_t * siridb);
void siridb_pools_free(siridb_pools_t * pools);
siridb_lookup_t * siridb_pools_gen_lookup(uint_fast16_t num_pools);
int siridb_pools_online(siridb_t * siridb);
int siridb_pools_available(siridb_t * siridb);
void siridb_pools_send_pkg(
        siridb_t * siridb,
        sirinet_pkg_t * pkg,
        uint64_t timeout,
        sirinet_promises_cb cb,
        void * data);
