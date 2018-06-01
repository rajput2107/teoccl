/*
 * The MIT License
 *
 * Copyright 2016-2018 Kirill Scherba <kirill@scherba.ru>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * \file  map 
 * \Author max <mpano91@gmail.com>
 *
 * Teo ccl Map C++ wrapper
 *
 * Created on March 25, 2018, 2:25 PM
 */

#ifndef MAP_HXX
#define MAP_HXX

#include <string>
#include <stdlib.h>

#include "map.h"

namespace teo {

  class Map {
    
  private:

    teoMap *map;

  public:

    Map() { map = teoMapNew(HASH_TABLE_SIZE, 1); }
    Map(size_t size, int auto_resize_f)
    {
      map = teoMapNew(size, auto_resize_f);
    }
    
    virtual ~Map() { teoMapDestroy(map); }


    // size
    inline size_t size() {
      return teoMapSize(map);
    }

    inline void mapClear() {
      teoMapClear(map);
    }

    inline void *getFirst(size_t *data_length) {
      return teoMapGetFirst(map, data_length);
    }


    // add
    inline void *add(void *key, size_t key_length, void *data,
        size_t data_length) {
      return teoMapAdd(map, key, key_length, data, data_length);
    }

    inline void *add(const std::string& key, const std::string& data) {
      return add((void *)key.c_str(), key.size() + 1, (void *)data.c_str(),
          data.size() + 1);
    }

    template<typename D>
    void *add(const std::string& key, const D& data) {
      return add((void*)key.c_str(), key.size() + 1, (void *)&data, sizeof(D));
    }

    template<typename K, typename D>
    void *add(const K& key, const D& data) {
      return add((void*)&key, sizeof(K), (void *)&data, sizeof(D));
    }


    // get
    inline void *get(void *key, size_t key_length, size_t *data_length) {
      return teoMapGet(map, key, key_length, data_length);
    }

    inline void *get(const std::string& key, size_t *data_length) {
      return get((void *)key.c_str(), key.size() + 1, data_length);
    }

    template<typename K>
    void *get(const K& key, size_t *data_length) {
      return get((void *)&key, sizeof(K), data_length);
    }


    // delete
    inline int deleteByKey(void *key, size_t key_length) {
      return teoMapDelete(map, key, key_length);
    }

    inline int deleteByKey(const std::string& key) {
      return deleteByKey((void *)key.c_str(), key.size() + 1);
    }

    template<typename K>
    int deleteByKey(const K& key) {
      return deleteByKey((void *)&key, sizeof(K));
    }


    // get iterator new(normal)
    inline teoMapIterator *iterator() {
      return teoMapIteratorNew(map);
    }
 
    // get iterator new(reverse)
    inline teoMapIterator *iteratorReverse() {
      return teoMapIteratorReverseNew(map);
    }

    // iterator next
    inline teoMapElementData *iteratorNext(teoMapIterator *it) {
      return teoMapIteratorNext(it);
    }
 
    // iterator prev
    inline teoMapElementData *iterator_prev(teoMapIterator *it) {
      return teoMapIteratorPrev(it);
    }

    // iterator free
    inline int iteratorFree(teoMapIterator *it) {
      return teoMapIteratorDestroy(it);
    }
 
    // get element
    inline teoMapElementData *mapItEl(teoMapIterator *it) {
      return teoMapIteratorElement(it);
    }

    // get key
    inline void *mapItElKey(teoMapElementData *el, size_t *key_length) {
      return teoMapIteratorElementKey(el, key_length);
    }

    // get data
    inline void *mapItElData(teoMapElementData *el, size_t *data_length) {
      return teoMapIteratorElementData(el, data_length);
    }

  };

}
#endif /* MAP_HXX */