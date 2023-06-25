from typing import List
from ..BaseService import BaseService
from bd.Models.Models import ContatoModel

class ContatoService(BaseService):
    def __init__(self) -> None:
        super().__init__(ContatoModel)

