#include "handle_wrapper.h"

HandleWrapper::HandleWrapper() noexcept
	: handle{ nullptr }
{
}

HandleWrapper::HandleWrapper(const HandleWrapper& other) noexcept
	: handle{ other.handle }
{
}

HandleWrapper::HandleWrapper(HandleWrapper&& other) noexcept
	: handle{ other.handle }
{
	other.handle = nullptr;
}

HandleWrapper::HandleWrapper(const HANDLE& handle) noexcept
	: handle{ handle }
{
}

HandleWrapper::HandleWrapper(HANDLE&& handle) noexcept
	: handle{ handle }
{
	handle = nullptr;
}

HandleWrapper::~HandleWrapper()
{
	if (!IsValid()) return;
	CloseHandle(handle);
	handle = nullptr;
}

HandleWrapper& HandleWrapper::operator=(const HandleWrapper& other) noexcept
{
	handle = other.handle;
	return *this;
}

HandleWrapper& HandleWrapper::operator=(HandleWrapper&& other) noexcept
{
	handle = other.handle;
	other.handle = nullptr;
	return *this;
}

HandleWrapper& HandleWrapper::operator=(const HANDLE& handle) noexcept
{
	this->handle = handle;
	return *this;
}

HandleWrapper& HandleWrapper::operator=(HANDLE&& handle) noexcept
{
	this->handle = handle;
	handle = nullptr;
	return *this;
}

HandleWrapper::operator HANDLE() const
{
	return handle;
}

bool HandleWrapper::IsValid() const noexcept
{
	return handle != nullptr && handle != INVALID_HANDLE_VALUE;
}
