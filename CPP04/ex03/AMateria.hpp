#pragma once

class AMateria
{
	protected:
		[...];
	public:
/* ================= Constructor & Destructor ================= */

		AMateria(std::string const & type);
		[...];	

/* ========================= Getter ========================= */

		std::string const & getType() const; //Returns the materia type
		
/* ========================= Else ========================= */

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
