#include"factory.h"

int main(int arg,char **argv) {
	//�򵥹���ģʽ
	//Factory pf = Factory();
	//int id;
	//std::cin >> id;
	//std::vector<Figure *> vf;
	//vf.push_back(pf.createFigure(id));
	std::vector<Factory *>_facs;
	//������,���µ�ͼ����Ҫ���ӵ�ʱ��ֻ��Ҫ������ͼ�εĹ������µ�ͼ�Σ������߼������޸ģ�����չ�ԣ���ͬʱ�����˴��Ĵ�������
	//����Щ������Ҳ���ӱ���ά��
	_facs.push_back(new LineFactory(2));
	_facs.push_back(new CircleFactory(1));
	_facs.push_back(new RectangleFactory(3));

	int id;
	std::vector<Figure *>_vf;
	while (std::cin >> id)
	{
		for (std::vector<Factory*>::iterator b = _facs.begin(); b != _facs.end(); ++b)
		{
			if ((*b)->getId() == id)//����ID ��ʹ�ò�ͬ�Ĺ�����������ͬ��ͼ��
			{
				_vf.push_back((*b)->createFigure());
			}
		}
	}
	for (std::vector<Figure*>::iterator b = _vf.begin(); b != _vf.end(); ++b)
	{
		(*b)->draw();
	}

	return 0;
}