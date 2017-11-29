# ifndef __LINK_H
#define __LINK_H

class Link
{
	private:
		string link_disp;
		string link_addr;
	public:
		Link() {cout << "Link demo running"; }
		Link(const string disp, const string addr)
		{
			link_disp = disp;
			link_addr=addr;
		}
		string print() { return link_disp; }
		string go() {return link_addr; }
};

 

#endif
