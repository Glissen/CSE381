#include <windows.h>
#include <windowsx.h>
#include <d2d1.h>
#include <list>
#include <memory>
#pragma comment(lib, "d2d1")
#include "basewin.h"
#include "plane.h"
#include "helpfuncs.h"

template <class T> void SafeRelease(T** ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}
class DPIScale
{
	static float scaleX;
	static float scaleY;

public:
	static void Initialize(ID2D1Factory* pFactory)
	{
		FLOAT dpiX, dpiY;
		#pragma warning(suppress: 4996);
		pFactory->GetDesktopDpi(&dpiX, &dpiY);
		scaleX = dpiX / 96.0f;
		scaleY = dpiY / 96.0f;
	}

	template <typename T>
	static float PixelsToDipsX(T x)
	{
		return static_cast<float>(x) / scaleX;
	}

	template <typename T>
	static float PixelsToDipsY(T y)
	{
		return static_cast<float>(y) / scaleY;
	}
};
float DPIScale::scaleX = 1.0f;
float DPIScale::scaleY = 1.0f;
struct point
{
	D2D1_ELLIPSE    ellipse;
	int originalX;
	int originalY;
	D2D1_COLOR_F    color;
	

	void Draw(ID2D1RenderTarget* pRT, ID2D1SolidColorBrush* pBrush)
	{
		pBrush->SetColor(color);
		pRT->FillEllipse(ellipse, pBrush);
		/*pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::White));
		pRT->DrawEllipse(ellipse, pBrush, 0.1f);*/
	}

	BOOL HitTest(float x, float y)
	{
		const float a = ellipse.radiusX;
		const float b = ellipse.radiusY;
		const float x1 = x - ellipse.point.x;
		const float y1 = y - ellipse.point.y;
		const float d = ((x1 * x1) / (a * a)) + ((y1 * y1) / (b * b));
		return d <= 1.0f;
	}
};
class MainWindow : public BaseWindow<MainWindow>
{
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;
	/*D2D1_ELLIPSE ellipse;*/
	void CalculateLayout();
	HRESULT CreateGraphicsResources();
	void DiscardGraphicsResources();
	void OnPaint();
	void Resize();
public:
	MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL)
	{
	}
	PCWSTR ClassName() const { return L"Convex Hull Algorithms Class"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
class PlaneWindow : public Plane<PlaneWindow>
{
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;
	ID2D1SolidColorBrush* pointBrush;
	ID2D1SolidColorBrush* edgeBrush;
	ID2D1SolidColorBrush* sumBrush;
	D2D1_POINT_2F ptMouse;


	int mode = 4;
	int scale = 10;
	signed short delta;

	std::list<std::shared_ptr<point>> points;
	//std::list<std::shared_ptr<point>> edges;
	std::list<std::shared_ptr<point>>::iterator selection;

	std::list<std::shared_ptr<polygon_pos>> shapes;
	std::list <std::shared_ptr<polygon_pos>>::iterator shape_selection;
	std::list<std::shared_ptr<polygon_pos>> shapes2;
	std::list <std::shared_ptr<polygon_pos>>::iterator shape_selection2;

	int polygon_selection = -1;

	int oldX = -1, oldY = -1;

	std::list<std::shared_ptr<point>> points2;
	std::list<std::shared_ptr<point>>::iterator selection2;

	std::shared_ptr<point> Selection()
	{
		if (selection == points.end())
		{
			return nullptr;
		}
		else
		{
			return (*selection);
		}
	}
	void ClearSelection() { selection = points.end(); }

	std::shared_ptr<point> Selection2()
	{
		if (selection2 == points2.end())
		{
			return nullptr;
		}
		else
		{
			return (*selection2);
		}
	}
	void ClearSelection2() { selection2 = points2.end(); }

	std::shared_ptr<polygon_pos> Shape_Selection()
	{
		if (shape_selection == shapes.end())
		{
			return nullptr;
		}
		else
		{
			return (*shape_selection);
		}
	}
	void ClearShapeSelection() { shape_selection = shapes.end(); }

	std::shared_ptr<polygon_pos> Shape_Selection2()
	{
		if (shape_selection2 == shapes2.end())
		{
			return nullptr;
		}
		else
		{
			return (*shape_selection2);
		}
	}
	void ClearShapeSelection2() { shape_selection2 = shapes2.end(); }


	HRESULT InsertPoint(float x, float y);
	HRESULT InsertPoint2(float x, float y);
	BOOL HitTest(float x, float y);
	BOOL HitTest2(float x, float y);
	void OnLButtonDown(int pixelX, int pixelY, DWORD flags);
	void OnMouseMove(int pixelX, int pixelY, DWORD flags);
	void OnLButtonUp();
	void OnMouseWheel(WPARAM wParam);

	void CalculateLayout();
	HRESULT CreateGraphicsResources();
	void DiscardGraphicsResources();
	void OnPaint();
	void Resize();
public:
	PlaneWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL), pointBrush(NULL)
	{
	}
	PCWSTR ClassName() const { return L"Plane Class"; }
	LRESULT PlaneMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void ChangeMode(WPARAM wParam);
};
// Recalculate drawing layout when the size of the window changes.
void MainWindow::CalculateLayout()
{
	if (pRenderTarget != NULL)
	{
		/*D2D1_SIZE_F size = pRenderTarget->GetSize();
		const float x = size.width / 2;
		const float y = size.height / 2;
		const float radius = min(x, y);
		ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);*/
	}
}
HRESULT MainWindow::CreateGraphicsResources()
{
	HRESULT hr = S_OK;
	if (pRenderTarget == NULL)
	{
		RECT rc;
		GetClientRect(m_hwnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
		hr = pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(m_hwnd, size),
			&pRenderTarget);
		if (SUCCEEDED(hr))
		{
			const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
			hr = pRenderTarget->CreateSolidColorBrush(color, &pBrush);
			if (SUCCEEDED(hr))
			{
				CalculateLayout();
			}
		}
	}
	return hr;
}
void MainWindow::DiscardGraphicsResources()
{
	SafeRelease(&pRenderTarget);
	SafeRelease(&pBrush);
}
void MainWindow::OnPaint()
{
	HRESULT hr = CreateGraphicsResources();
	if (SUCCEEDED(hr))
	{
		PAINTSTRUCT ps;
		BeginPaint(m_hwnd, &ps);
		pRenderTarget->BeginDraw();
		pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
		//pRenderTarget->FillEllipse(ellipse, pBrush);
		hr = pRenderTarget->EndDraw();
		if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET)
		{
			DiscardGraphicsResources();
		}
		EndPaint(m_hwnd, &ps);
	}
}

void PlaneWindow::ChangeMode(WPARAM wParam) {
	WORD new_mode = LOWORD(wParam);
	mode = new_mode - 100;
	CalculateLayout();
	InvalidateRect(m_hwnd, NULL, FALSE);
}

void PlaneWindow::OnLButtonDown(int pixelX, int pixelY, DWORD flags)
{
	const float dipX = DPIScale::PixelsToDipsX(pixelX);
	const float dipY = DPIScale::PixelsToDipsY(pixelY);

	if (HitTest(dipX, dipY))
	{
		OutputDebugStringA("Holleuoueu");
		SetCapture(m_hwnd);
		ptMouse = Selection()->ellipse.point;
		ptMouse.x -= dipX;
		ptMouse.y -= dipY;
		return;
	}
	if (HitTest2(dipX, dipY))
	{
		OutputDebugStringA("Holleuoueu2222222222");
		SetCapture(m_hwnd);
		ptMouse = Selection2()->ellipse.point;
		ptMouse.x -= dipX;
		ptMouse.y -= dipY;
		return;
	}

	point_pos click;
	click.x = dipX;
	click.y = dipY;

	polygon_pos polygon;
	for (auto i = points.rbegin(); i != points.rend(); ++i)
	{
		point_pos temp;
		temp.x = (*i)->ellipse.point.x;
		temp.y = (*i)->ellipse.point.y;
		polygon.push_back(temp);
	}
	polygon_pos* temp = QuickHull(polygon);
	if (Contains(*temp, click)) {
		polygon_selection = 0;
		oldX = dipX;
		oldY = dipY;
		delete(temp);
		return;
	}
	delete(temp);
	polygon_pos polygon2;
	for (auto i = points2.rbegin(); i != points2.rend(); ++i)
	{
		point_pos temp;
		temp.x = (*i)->ellipse.point.x;
		temp.y = (*i)->ellipse.point.y;
		polygon2.push_back(temp);
	}
	temp = QuickHull(polygon2);
	if (Contains(*temp, click)) {
		polygon_selection = 1;
		oldX = dipX;
		oldY = dipY;
		delete(temp);
		return;
	}
	delete(temp);
}

void PlaneWindow::OnMouseMove(int pixelX, int pixelY, DWORD flags)
{
	const float dipX = DPIScale::PixelsToDipsX(pixelX);
	const float dipY = DPIScale::PixelsToDipsY(pixelY);

	if (flags & MK_LBUTTON)
	{
		if (Selection())
		{
			Selection()->ellipse.point.x = dipX + ptMouse.x;
			Selection()->originalX = dipX + ptMouse.x;
			Selection()->ellipse.point.y = dipY + ptMouse.y;
			Selection()->originalY = dipY + ptMouse.y;
		}
		else if (Selection2()) {
			Selection2()->ellipse.point.x = dipX + ptMouse.x;
			Selection2()->originalX = dipX + ptMouse.x;
			Selection2()->ellipse.point.y = dipY + ptMouse.y;
			Selection2()->originalY = dipY + ptMouse.y;
		}
		else if (polygon_selection == 0) {
			for (auto i = points.begin(); i != points.end(); ++i)
			{
				(*i)->ellipse.point.x += dipX - oldX;
				(*i)->originalX += dipX - oldX;
				(*i)->ellipse.point.y += dipY  - oldY;
				(*i)->originalY += dipY - oldY;
			}
			oldX = dipX;
			oldY = dipY;
		}
		else if (polygon_selection == 1) {
			for (auto i = points2.begin(); i != points2.end(); ++i)
			{
				(*i)->ellipse.point.x += dipX - oldX;
				(*i)->originalX += dipX - oldX;
				(*i)->ellipse.point.y += dipY - oldY;
				(*i)->originalY += dipY - oldY;
			}
			oldX = dipX;
			oldY = dipY;
		}
		InvalidateRect(m_hwnd, NULL, FALSE);
	}
}

void PlaneWindow::OnLButtonUp()
{
	oldX = -1;
	oldY = -1;
	polygon_selection = -1;
	ClearSelection();
	ClearSelection2();
	ReleaseCapture();
}
void PlaneWindow::OnMouseWheel(WPARAM wParam)
{
	delta += HIWORD(wParam);

	while (delta >= 120) 
	{
		if (scale < 50)
			scale += 1;
		delta -= 120;
	}
	while (delta <= -120)
	{
		if (scale >= 11)
			scale -= 1;
		delta += 120;
	}
	InvalidateRect(m_hwnd, NULL, FALSE);
}

HRESULT PlaneWindow::InsertPoint(float x, float y)
{
	try
	{
		selection = points.insert(
			points.end(),
			std::shared_ptr<point>(new point()));

		Selection()->ellipse.point = ptMouse = D2D1::Point2F(x, y);
		Selection()->ellipse.radiusX = 10.0f; 
		Selection()->ellipse.radiusY = 10.0f;
		Selection()->originalX = x;
		Selection()->originalY = y;
		Selection()->color = D2D1::ColorF(D2D1::ColorF::Green);
		ClearSelection();
		//Selection()->ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), 8, 8);
	}
	catch (std::bad_alloc)
	{
		return E_OUTOFMEMORY;
	}
	return S_OK;
}

HRESULT PlaneWindow::InsertPoint2(float x, float y)
{
	try
	{
		selection2 = points2.insert(
			points2.end(),
			std::shared_ptr<point>(new point()));

		Selection2()->ellipse.point = ptMouse = D2D1::Point2F(x, y);
		Selection2()->ellipse.radiusX = 10.0f;
		Selection2()->ellipse.radiusY = 10.0f;
		Selection2()->originalX = x;
		Selection2()->originalY = y;
		Selection2()->color = D2D1::ColorF(D2D1::ColorF::Green);
		ClearSelection2();
		//Selection()->ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), 8, 8);
	}
	catch (std::bad_alloc)
	{
		return E_OUTOFMEMORY;
	}
	return S_OK;
}
BOOL PlaneWindow::HitTest(float x, float y)
{
	for (auto i = points.rbegin(); i != points.rend(); ++i)
	{
		if ((*i)->HitTest(x, y))
		{
			selection = (++i).base();
			return TRUE;
		}
	}
	return FALSE;
}
BOOL PlaneWindow::HitTest2(float x, float y)
{
	for (auto i = points2.rbegin(); i != points2.rend(); ++i)
	{
		if ((*i)->HitTest(x, y))
		{
			selection2 = (++i).base();
			return TRUE;
		}
	}
	return FALSE;
}

void PlaneWindow::CalculateLayout()
{
	if (pRenderTarget != NULL)
	{
		/*D2D1_SIZE_F size = pRenderTarget->GetSize();
		const float x = size.width / 2;
		const float y = size.height / 2;
		const float radius = min(x, y);
		ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);*/
		points.clear();
		points2.clear();
		InsertPoint(300, 100);
		InsertPoint(200, 100);
		InsertPoint(150, 400);
		InsertPoint(400, 300);
		InsertPoint(200, 200);

		if (mode != 3 && mode != 4) {
			InsertPoint2(200, 200);
			InsertPoint2(300, 300);
			InsertPoint2(200, 300);
			InsertPoint2(50, 300);
		}
		
		if (mode == 4) {
			InsertPoint2(250, 250);
		}
	
		//InsertEdge(100, 100);
	}
}
HRESULT PlaneWindow::CreateGraphicsResources()
{
	HRESULT hr = S_OK;
	HRESULT hr1 = S_OK;
	HRESULT hr2 = S_OK;
	HRESULT hr3 = S_OK;
	if (pRenderTarget == NULL)
	{
		RECT rc;
		GetClientRect(m_hwnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
		hr = pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(m_hwnd, size),
			&pRenderTarget);
		if (SUCCEEDED(hr))
		{
			const D2D1_COLOR_F color = D2D1::ColorF(D2D1::ColorF::Gray, 1);
			hr = pRenderTarget->CreateSolidColorBrush(color, &pBrush);
			const D2D1_COLOR_F color2 = D2D1::ColorF(D2D1::ColorF::Green, 1);
			hr1 = pRenderTarget->CreateSolidColorBrush(color2, &pointBrush);
			const D2D1_COLOR_F color3 = D2D1::ColorF(D2D1::ColorF::White, 1);
			hr2 = pRenderTarget->CreateSolidColorBrush(color3, &edgeBrush);
			const D2D1_COLOR_F color4 = D2D1::ColorF(D2D1::ColorF::Purple, 1);
			hr3 = pRenderTarget->CreateSolidColorBrush(color4, &sumBrush);
			if (SUCCEEDED(hr) && SUCCEEDED(hr1) && SUCCEEDED(hr2) && SUCCEEDED(hr3))
			{
				CalculateLayout();
			}
		}
	}
	return hr;
}
void MainWindow::Resize()
{
	if (pRenderTarget != NULL)
	{
		RECT rc;
		GetClientRect(m_hwnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
		pRenderTarget->Resize(size);
		CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);
	}
}
void PlaneWindow::OnPaint()
{
	HRESULT hr = CreateGraphicsResources();

	if (SUCCEEDED(hr))
	{
		PAINTSTRUCT ps;
		BeginPaint(m_hwnd, &ps);
		pRenderTarget->BeginDraw();
		pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
		D2D1_SIZE_F size = pRenderTarget->GetSize();
		const float width = size.width;
		const float height = size.height;

		D2D_POINT_2F x, y;
		x = D2D1::Point2F(width / 2, 0);
		y = D2D1::Point2F(width / 2, height);
		pRenderTarget->DrawLine(x, y, pBrush, 5);
		x = D2D1::Point2F(0, height / 2);
		y = D2D1::Point2F(width, height / 2);
		pRenderTarget->DrawLine(x, y, pBrush, 5);
		for (auto i = width / 2; i < width; i += 20 * (scale / 10.0)) {
			x = D2D1::Point2F(i, 0);
			y = D2D1::Point2F(i, height);
			pRenderTarget->DrawLine(x, y, pBrush, 1);
		}
		for (auto i = width / 2; i > 0; i -= 20 * (scale / 10.0)) {
			x = D2D1::Point2F(i, 0);
			y = D2D1::Point2F(i, height);
			pRenderTarget->DrawLine(x, y, pBrush, 1);
		}
		for (auto i = height / 2; i < height; i += 20 * (scale / 10.0)) {
			x = D2D1::Point2F(0, i);
			y = D2D1::Point2F(width, i);
			pRenderTarget->DrawLine(x, y, pBrush, 1);
		}
		for (auto i = height / 2; i > 0; i -= 20 * (scale / 10.0)) {
			x = D2D1::Point2F(0, i);
			y = D2D1::Point2F(width, i);
			pRenderTarget->DrawLine(x, y, pBrush, 1);
		}

		for (auto i = points.begin(); i != points.end(); ++i)
		{
			int deltaX = (*i)->originalX - 300;
			int deltaY = (*i)->originalY - 300;
			(*i)->ellipse.point.x = 600 / 2 + deltaX * (scale / 10.0);
			(*i)->ellipse.point.y = 600 / 2 + deltaY * (scale / 10.0);
			if (mode != 4) {
				(*i)->Draw(pRenderTarget, pointBrush);
				pRenderTarget->FillEllipse((*i)->ellipse, pointBrush);
			}
		}

		polygon_pos polygon;
		for (auto i = points.rbegin(); i != points.rend(); ++i)
		{
			point_pos temp;
			temp.x = (*i)->ellipse.point.x;
			temp.y = (*i)->ellipse.point.y;
			polygon.push_back(temp);
		}
		polygon_pos *temp = QuickHull(polygon);

		for (auto i = points2.begin(); i != points2.end(); ++i)
		{
			int deltaX = (*i)->originalX - 300;
			int deltaY = (*i)->originalY - 300;
			(*i)->ellipse.point.x = 600 / 2 + deltaX * (scale / 10.0);
			(*i)->ellipse.point.y = 600 / 2 + deltaY * (scale / 10.0);
			(*i)->Draw(pRenderTarget, pointBrush);
			if (mode == 4) {
				point_pos pt;
				pt.x = (*i)->ellipse.point.x;
				pt.y = (*i)->ellipse.point.y;
				if (Contains(*temp, pt))
					pRenderTarget->FillEllipse((*i)->ellipse, sumBrush);
				else
					pRenderTarget->FillEllipse((*i)->ellipse, pointBrush);
			}
		}
		
		D2D_POINT_2F p1, p2;
		auto i = 0, j = 1;
		for (; j < temp->size(); ++i, ++j) {
			p1.x = temp->at(i).x;
			p1.y = temp->at(i).y;
			p2.x = temp->at(j).x;
			p2.y = temp->at(j).y;
			pRenderTarget->DrawLine(p1, p2, edgeBrush, 2);
		}
		i = 0;
		j--;
		p1.x = temp->at(i).x;
		p1.y = temp->at(i).y;
		p2.x = temp->at(j).x;
		p2.y = temp->at(j).y;
		pRenderTarget->DrawLine(p1, p2, edgeBrush, 2);
		delete(temp);

		polygon_pos polygon2;
		if (mode != 3 && mode != 4) {
			for (auto i = points2.rbegin(); i != points2.rend(); ++i)
			{
				point_pos temp;
				temp.x = (*i)->ellipse.point.x;
				temp.y = (*i)->ellipse.point.y;
				polygon2.push_back(temp);
			}
			temp = QuickHull(polygon2);

			i = 0, j = 1;
			for (; j < temp->size(); ++i, ++j) {
				p1.x = temp->at(i).x;
				p1.y = temp->at(i).y;
				p2.x = temp->at(j).x;
				p2.y = temp->at(j).y;
				pRenderTarget->DrawLine(p1, p2, edgeBrush, 2);
			}
			i = 0;
			j--;
			p1.x = temp->at(i).x;
			p1.y = temp->at(i).y;
			p2.x = temp->at(j).x;
			p2.y = temp->at(j).y;
			pRenderTarget->DrawLine(p1, p2, edgeBrush, 2);
			delete(temp);
		}


		if (mode == 1 || mode == 2 || mode == 5) {
			if (mode == 1 || mode == 5) {
				temp = MinkowskiDifference(polygon, polygon2, { (int)width / 2, (int)height / 2 });
			}
			else 
				temp = MinkowskiSum(polygon, polygon2, { (int)width / 2, (int)height / 2 });
			i = 0, j = 1;
			bool blah = Contains(*temp, { (int)width / 2, (int)height / 2 }) && mode == 5;
			for (; j < temp->size(); ++i, ++j) {
				p1.x = temp->at(i).x;
				p1.y = temp->at(i).y;
				p2.x = temp->at(j).x;
				p2.y = temp->at(j).y;
				if (blah)
					pRenderTarget->DrawLine(p1, p2, pointBrush, 2);
				else
					pRenderTarget->DrawLine(p1, p2, sumBrush, 2);
			}
			i = 0;
			j--;
			p1.x = temp->at(i).x;
			p1.y = temp->at(i).y;
			p2.x = temp->at(j).x;
			p2.y = temp->at(j).y;
			if (blah)
				pRenderTarget->DrawLine(p1, p2, pointBrush, 2);
			else
				pRenderTarget->DrawLine(p1, p2, sumBrush, 2);
			delete(temp);
		}


		//pRenderTarget->FillEllipse(ellipse, pBrush);
		hr = pRenderTarget->EndDraw();
		if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET)
		{
			DiscardGraphicsResources();
		}
		EndPaint(m_hwnd, &ps);
	}
}
void PlaneWindow::Resize()
{
	if (pRenderTarget != NULL)
	{
		RECT rc;
		GetClientRect(m_hwnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
		pRenderTarget->Resize(size);
		CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);
		
	}
}
void PlaneWindow::DiscardGraphicsResources()
{
	SafeRelease(&pRenderTarget);
	SafeRelease(&pBrush);
}
void AddControls(HWND hWnd)
{
	CreateWindowW(L"Button", L"Minkowski Difference", WS_VISIBLE | WS_CHILD, 50, 50, 150, 40, hWnd, (HMENU)101, NULL, NULL);
	CreateWindowW(L"Button", L"Minkowski Sum", WS_VISIBLE | WS_CHILD, 50, 100, 150, 40, hWnd, (HMENU)102, NULL, NULL);
	CreateWindowW(L"Button", L"Quickhull", WS_VISIBLE | WS_CHILD, 50, 150, 150, 40, hWnd, (HMENU)103, NULL, NULL);
	CreateWindowW(L"Button", L"Point Convex Hull", WS_VISIBLE | WS_CHILD, 50, 200, 150, 40, hWnd, (HMENU)104, NULL, NULL);
	CreateWindowW(L"Button", L"GJK", WS_VISIBLE | WS_CHILD, 50, 250, 150, 40, hWnd, (HMENU)105, NULL, NULL);
}
PlaneWindow plane;
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
	MainWindow win;
	if (!win.Create(L"Convex Hull Algorithms", WS_OVERLAPPEDWINDOW))
	{
		return 0;
	}
	ShowWindow(win.Window(), nCmdShow);

	RECT x;
	GetClientRect(win.Window(), &x);
	if (!plane.Create(L"Plane1", WS_CHILD | WS_VISIBLE, 0, 300, 50, 600, 600, win.Window(), NULL))
	{
		return 0;
	}
	ShowWindow(plane.Window(), nCmdShow);
	GetClientRect(plane.Window(), &x);
	// Run the message loop.
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		if (FAILED(D2D1CreateFactory(
			D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory)))
		{
			return -1; // Fail CreateWindowEx.
		}
		AddControls(m_hwnd);
		return 0;
	case WM_DESTROY:
		DiscardGraphicsResources();
		SafeRelease(&pFactory);
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		OnPaint();
		return 0;
	case WM_SIZE:
		Resize();
		return 0;
	case WM_COMMAND:
	{
		plane.ChangeMode(wParam);
	}
		return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
LRESULT PlaneWindow::PlaneMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		if (FAILED(D2D1CreateFactory(
			D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory)))
		{
			return -1; // Fail CreateWindowEx.
		}
		return 0;
	case WM_DESTROY:
		DiscardGraphicsResources();
		SafeRelease(&pFactory);
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		OnPaint();
		return 0;
	case WM_SIZE:
		Resize();
		return 0;
	case WM_LBUTTONDOWN:
		OnLButtonDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), (DWORD)wParam);
		return 0;
	case WM_MOUSEMOVE:
		OnMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), (DWORD)wParam);
		return 0;
	case WM_LBUTTONUP:
		OnLButtonUp();
		return 0;
	case WM_MOUSEWHEEL:
		OnMouseWheel(wParam);
		return 0;
	}

	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}