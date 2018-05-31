//
// Created by Acer on 2018-05-29.
//

#ifndef OOP_TASK_4_MYVECTOR_H
#define OOP_TASK_4_MYVECTOR_H
#include <memory>
#include <vector>

template< class T, class Allocator = std::allocator<T>> class Vector {
public:

    typedef T value_type;
    typedef Allocator allocator_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef typename std::allocator_traits<Allocator>::pointer pointer;
    typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


    Vector() noexcept : sz(0), cap(0) {elem = allocatorius.allocate(0);}
    explicit Vector( const Allocator& alloc ) : sz(0), cap(0), allocatorius(alloc) {elem = allocatorius.allocate(0);}
    Vector( size_type count, const T& value, const Allocator& alloc = Allocator()) : sz(count), cap(count), allocatorius(alloc) {
        elem = allocatorius.allocate(cap);
        std::fill(elem, elem+count, value);
    }
    explicit Vector( size_type count, const Allocator& alloc = Allocator() ): sz(count), cap(count), allocatorius(alloc){
        elem = allocatorius.allocate(cap);
        std::fill(elem, elem+count, T{});
    }
    template< class InputIt > Vector( InputIt first, InputIt last, const Allocator& alloc = Allocator()) : allocatorius(alloc) {
        cap = std::distance(first, last);
        sz = cap;
        elem = allocatorius.allocate(cap);
        std::copy(first, last, elem);
    }
    Vector( const Vector& other ) : sz(other.sz), cap(other.cap), allocatorius(std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.allocatorius)) {
        elem = allocatorius.allocate(sz);
        std::copy(elem, elem + sz, elem);
    }
    Vector( const Vector& other, const Allocator& alloc ) : sz(other.sz), cap(other.cap), allocatorius(std::allocator_traits<allocator_type>::select_on_container_copy_construction(alloc)){
        elem = allocatorius.allocate(sz);
        std::copy(elem, elem + sz, elem);
    }
    Vector( Vector&& other ) noexcept : sz(std::move(other.sz)), cap(std::move(other.cap)), allocatorius(allocatorius = std::move(other.allocatorius)), elem(other.elem){
        other.sz = 0;
        other.cap = 0;
        other.elem = nullptr;
    }
    Vector( Vector&& other, const Allocator& alloc ) : sz(std::move(other.sz)), cap(std::move(other.cap)), allocatorius(std::move(alloc)), elem(other.elem){
        other.sz = 0;
        other.cap = 0;
        other.elem = nullptr;
    }
    Vector( std::initializer_list<T> init, const Allocator& alloc = Allocator() ) : sz(init.size()), cap(init.size()), allocatorius(alloc){
        elem = allocatorius.allocate(init.size());
        std::move(init.begin(), init.end(), elem);
    }

private:
    //Members
    T* elem;
    size_type sz;
    size_type cap;
    allocator_type allocatorius{};

    //

public:

    Vector& operator=(const Vector& other){
        if (std::allocator_traits<allocator_type>::propagate_on_container_copy_assignment::value){ allocatorius = other.allocatorius; }
        if (allocatorius != other.allocatorius){
            allocatorius.deallocate(elem, sz);
            allocatorius = other.allocatorius;
            elem = allocatorius.allocate(other.sz);
        }
        sz = other.sz;
        cap = other.cap;
        std::copy(other.elem,other.elem + sz,elem);
        return *this;
    }
    /*
     *Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container).
     * other is in a valid but unspecified state afterwards.
     * If std::allocator_traits<allocator_type>::propagate_on_container_move_assignment::value is true,
     * the target allocator is replaced by a copy of the source allocator.
     * If it is false and the source and the target allocators do not compare equal,
     * the target cannot take ownership of the source memory and must move-assign each element individually,
     * allocating additional memory using its own allocator as needed.
     * In any case, all elements originally present in *this are either destroyed or replaced by elementwise move-assignment.
     *
     */
    Vector& operator=(Vector&& other) noexcept { //Q. Augis
        if (std::allocator_traits<allocator_type>::propagate_on_container_copy_assignment::value){ allocatorius = other.allocatorius; }
        allocatorius.deallocate(elem, sz);
        allocatorius = other.allocatorius;
        sz = other.sz;
        cap = other.cap;
        std::move(other.elem,other.elem + sz,elem);
        other.elem = nullptr;
        other.sz = 0;
        return *this;
    }
    Vector &operator=(std::initializer_list<T> ilist){
        allocatorius.deallocate(elem, sz);
        elem = allocatorius.allocate(ilist.size());
        sz = ilist.size();
        cap = ilist.size();
        std::copy(ilist.begin(),ilist.end(),elem);
        return *this;
    }
    void assign(size_type count, const T& value){
        allocatorius.deallocate(elem, sz);
        elem = allocatorius.allocate(count);
        std::fill(elem, elem + count, value);
        sz = count;
        cap = count;
    }
    void assign(iterator first, iterator last){
        auto count = std::distance(first, last);
        allocatorius.deallocate(elem, sz);
        elem = allocatorius.allocate(count);
        std::copy(first,last,elem);
        sz = count;
        cap = count;
    }
    void assign(std::initializer_list<T> ilist){
        allocatorius.deallocate(elem, sz);
        elem = allocatorius.allocate(ilist.size());
        std::copy(ilist.begin(),ilist.end(),elem);
        sz = ilist.size();
        cap = ilist.size();
    }
    allocator_type get_allocator() const{
        return allocatorius;
    }


    iterator begin() noexcept{return elem; }
    const_iterator begin() const noexcept{return elem; }
    const_iterator cbegin() const noexcept{return elem; }

    iterator end() noexcept{return elem + sz; }
    const_iterator end() const noexcept{return elem + sz; }
    const_iterator cend() const noexcept{return elem + sz; }

    reverse_iterator rbegin() noexcept{return reverse_iterator(elem + sz - 1); }
    const_reverse_iterator rbegin() const noexcept{return reverse_iterator(elem + sz - 1); }
    const_reverse_iterator crbegin() const noexcept{return reverse_iterator(elem + sz - 1); }

    reverse_iterator rend() noexcept{return reverse_iterator(elem - 1); }
    const_reverse_iterator rend() const noexcept{return reverse_iterator(elem - 1); }
    const_reverse_iterator crend() const noexcept{return reverse_iterator(elem - 1); }




    bool empty() const noexcept{return sz == 0; }
    size_type size() const noexcept{return sz; }
    size_type max_size() const noexcept{return allocatorius.max_size();}

    void reserve(size_type new_cap){
        if (new_cap > max_size()) throw std::length_error("Vector::reserve(size_type new_cap)");
        if (new_cap > cap) {
            value_type* p = allocatorius.allocate(new_cap);
            std::move(begin(),end(),p);
            allocatorius.deallocate(elem, cap);
            elem = p;
            cap = new_cap;
        }
    }

    size_type capacity() const noexcept{return cap; }

    void shrink_to_fit(){
        if (sz != cap){
            value_type * p = allocatorius.allocate(sz);
            std::move(begin(),end(),p);
            allocatorius.deallocate(elem, cap);
            elem = p;
            cap = sz;
        }
    }



    void clear() noexcept{
        for (auto i = begin(); i != end(); i++) std::allocator_traits<Allocator>::destroy(allocatorius, i);
        sz = 0;
    }

    iterator insert( const_iterator pos, const T& value ){
        auto position = std::distance(cbegin(),pos);
        if (sz == cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem+position,n_elem);
            *(n_elem + position) = value;
            std::move(elem + position, elem + sz, n_elem + position + 1);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            std::move(elem + position, elem + sz, elem + position + 1);
            *(elem + position) = value;
        }
        sz++;
        return &elem[position];
    }

    iterator insert( const_iterator pos, T&& value ){
        auto position = std::distance(cbegin(),pos);
        if (sz == cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem+position,n_elem);
            *(n_elem + position) = std::move(value);
            std::move(elem + position, elem + sz, n_elem + position + 1);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            std::move(elem + position, elem + sz, elem + position + 1);
            *(elem + position) = std::move(value);
        }
        sz++;
        return &elem[position];
    }

    iterator insert( const_iterator pos, size_type count, const T& value ){
        if (count == 0) return &elem[pos];
        auto position = std::distance(cbegin(),pos);
        if (sz+count >= cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem+position,n_elem);
            std::fill_n(n_elem + position, count, value);
            std::move(elem + position, elem + sz, n_elem + position + count);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            std::move(elem + position, elem + sz, elem + position + count);
            std::fill_n(elem + position, count, value);
        }
        sz+= count;
        return &elem[position];
    }

    template< class InputIt >
    iterator insert( const_iterator pos, InputIt first, InputIt last ){
        if (first == last) return &elem[pos];
        auto position = std::distance(cbegin(),pos);
        auto count = std::distance(first, last);
        if (sz+count >= cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem+position,n_elem);
            std::copy(first, last, elem+position);
            std::move(elem + position, elem + sz, n_elem + position + count);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            std::move(elem + position, elem + sz, elem + position + count);
            std::copy(first, last, elem+position);
        }
        sz+=count;
        return &elem[position];
    }

    iterator insert( const_iterator pos, std::initializer_list<T> ilist ){
        if (ilist.size() == 0) return &elem[pos];
        auto position = std::distance(cbegin(),pos);
        auto count = ilist.size();
        if (sz+count >= cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem+position,n_elem);
            std::copy(ilist.begin(), ilist.end(), elem+position);
            std::move(elem + position, elem + sz, n_elem + position + count);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            std::move(elem + position, elem + sz, elem + position + count);
            std::copy(ilist.begin(), ilist.end(), elem+position);
        }
        sz+=count;
        return &elem[position];
    }

    template< class... Args >
    iterator emplace( const_iterator pos, Args&&... args ){

        auto position = std::distance(cbegin(),pos);
        if (sz == cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem+position,n_elem);
            allocatorius.construct(n_elem + position, std::forward<Args>(args)...);
            std::move(elem + position, elem + sz, n_elem + position + 1);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            std::move(elem + position, elem + sz, elem + position + 1);
            allocatorius.construct(elem + position, std::forward<Args>(args)...);
        }
        sz++;
        return &elem[position];
    }

    iterator erase( const_iterator pos ){
        auto position = std::distance(cbegin(),pos);
        allocatorius.destroy(pos);
        std::move(elem + position + 1, elem + sz, elem + position );
        sz--;
        return &elem[position];
    }

    void push_back( const T& value ){
        if (sz == cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::copy(elem,elem + sz ,n_elem);
            *(n_elem + sz) = value;
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            *(elem + sz) = value;
        }
        sz++;
    }

    void push_back( T&& value ){
        if (sz == cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem + sz ,n_elem);
            *(n_elem + sz) = std::move(value);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            *(elem + sz) = std::move(value);
        }
        sz++;
    }

    template< class... Args >
    reference emplace_back( Args&&... args ){
        if (sz == cap){
            if (cap == 0) cap = 1;
            else cap *= 2;
            value_type* n_elem = allocatorius.allocate(cap);
            std::move(elem,elem + sz ,n_elem);
            allocatorius.construct(n_elem + sz, std::forward<Args>(args)...);
            allocatorius.deallocate(elem, sz);
            elem = n_elem;
        } else{
            allocatorius.construct(elem + sz, std::forward<Args>(args)...);
        }
        sz++;
        return &elem[elem + sz - 1];
    }

    void pop_back(){
        sz--;
        allocatorius.destroy(elem +sz);
    }

    void resize( size_type count ){
        if (sz > count){
            sz = count;
        }
        else if (sz < count){
            if (count > max_size()) throw std::length_error("Vector::reserve(size_type new_cap)");
            if (cap < count){
                while (cap < count) cap *= 2;
                value_type* n_elem = allocatorius.allocate(cap);
                std::move(elem, elem + sz, n_elem);
                std::fill(n_elem + sz, n_elem + cap, T{});
                allocatorius.deallocate(elem,sz);
                elem = n_elem;
                sz = count;
            }
        }
    }

    void resize( size_type count, const value_type& value ){
        if (sz > count){
            sz = count;
        }
        else if (sz < count){
            if (count > max_size()) throw std::length_error("Vector::reserve(size_type new_cap)");
            if (cap < count){
                while (cap < count) cap *= 2;
                value_type* n_elem = allocatorius.allocate(cap);
                std::move(elem, elem + sz, n_elem);
                std::fill(n_elem + sz, n_elem + cap, value);
                allocatorius.deallocate(elem,sz);
                elem = n_elem;
                sz = count;
            }
        }
    }
};

template< class T, class Alloc > void swap( Vector<T,Alloc>& lhs, Vector<T,Alloc>& rhs ){
    Vector<T,Alloc> temp{std::move(lhs)};
    lhs = std::move(rhs);
    rhs = std::move(temp);
};

template< class T, class Alloc > bool operator==( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs ){
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(),lhs.end(),rhs.begin()));
};

template< class T, class Alloc > bool operator!=( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs ){
    return !(lhs.size() == rhs.size() && std::equal(lhs.begin(),lhs.end(),rhs.begin()));
};
template< class T, class Alloc > inline bool operator<( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs ){
    return std::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
};
template< class T, class Alloc > inline bool operator<=( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs ){
    return operator<(rhs,lhs);
};
template< class T, class Alloc > bool operator>( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs ){
    return !operator<(rhs,lhs);
};
template< class T, class Alloc > bool operator>=( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs ){
    return !operator<(lhs,rhs);
};




#endif //OOP_TASK_4_MYVECTOR_H
