from sqlalchemy import Column, Integer, String, Boolean, Table, ForeignKey
from sqlalchemy.orm import relationship
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

association_table_rele = Table('liga_rele_contatora', Base.metadata,
    Column('id_rele', Integer, ForeignKey('rele_model.id')),
    Column('id_contatora', Integer, ForeignKey('contat.id'))
)

association_table_contato = Table('liga_contato_aux', Base.metadata,
    Column('idCont', Integer, ForeignKey('contat.id')),
    Column('idAux', Integer, ForeignKey('aux.id'))
)

association_table_tensao = Table('liga_tensao_contatora', Base.metadata,
    Column('id_cont', Integer, ForeignKey('contat.id')),
    Column('id_v', Integer, ForeignKey('v.id'))
)

association_table_corrente = Table('liga_releCod_releModel', Base.metadata,
    Column('idCod', Integer, ForeignKey('rele_cod.id')),
    Column('idModel', Integer, ForeignKey('contat.id'))
)

class ContatoraModel(Base):
    __tablename__ = "contat"

    id = Column(Integer, primary_key=True)
    modelo = Column(String(32))
    reles = relationship('ReleModel', secondary=association_table_rele, back_populates='contatoras')
    contatos = relationship('ContatoModel', secondary=association_table_contato, back_populates='contatoras')
    tensoes = relationship('TensaoModel', secondary=association_table_tensao, back_populates='contatoras')
    correntes =  relationship('ReleCod', secondary=association_table_corrente, back_populates='contatoras')

class ReleModel(Base):
    __tablename__ = "rele_model"

    id = Column(Integer, primary_key=True)
    modelo = Column(String(32))
    contatoras = relationship('ContatoraModel', secondary=association_table_rele, back_populates='reles')

class ContatoModel(Base):
    __tablename__ = "aux"

    id = Column(Integer, primary_key=True)
    aberto = Column(Integer)
    fechado = Column(Integer)
    contatoras = relationship('ContatoraModel', secondary=association_table_contato, back_populates='contatos')

class TensaoModel(Base):
    __tablename__ = "v"

    id = Column(Integer, primary_key=True)
    v = Column(Integer, primary_key=True)
    cod_v = Column(String)
    isAc = Column(Boolean)
    contatoras = relationship('ContatoraModel', secondary=association_table_tensao, back_populates='tensoes')

class ReleCod(Base):
    __tablename__ = "rele_cod"

    id = Column(Integer, primary_key=True)
    cod = Column(String)
    imax = Column(Integer)
    imin = Column(Integer)
    contatoras = relationship('ContatoraModel', secondary=association_table_corrente, back_populates='correntes')