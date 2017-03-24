#include "wrap_thread.hpp"

wrap_thread::wrap_thread(wrap_thread &&rhm) noexcept {
	if(&rhm != this) {
		if(m_thr.joinable())
			m_thr.join();
		m_thr = std::move(rhm.m_thr);
	}
}

wrap_thread &wrap_thread::operator=(wrap_thread &&rhm) noexcept {
	if(&rhm == this) {
		return *this;
	}
	if(m_thr.joinable())
		m_thr.join();
	m_thr = std::move(rhm.m_thr);
	return *this;
}

bool wrap_thread::joinable() const noexcept {
	return m_thr.joinable();
}

std::thread::id wrap_thread::get_id() const noexcept {
	return m_thr.get_id();
}

void wrap_thread::join() {
	m_thr.join();
}

void wrap_thread::swap(wrap_thread &other) noexcept {
	m_thr.swap(other.m_thr);
}

wrap_thread::~wrap_thread()  {
	if(m_thr.joinable())
		m_thr.join();
}